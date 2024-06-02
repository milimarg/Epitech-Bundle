/*
** EPITECH PROJECT, 2024
** preparing-plazza
** File description:
** Reception
*/

#include "Reception.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

namespace plazza
{
    Reception &Reception::getInstance(double multiplier, int numCooksPerKitchen, int restockTime)
    {
        static Reception instance(multiplier, numCooksPerKitchen, restockTime);
        return instance;
    }

    Reception::Reception(
        double multiplier,
        int numCooksPerKitchen,
        int restockTime
    )
    : _breakLoop(false),
    _multiplier(multiplier),
    _numCooksPerKitchen(numCooksPerKitchen),
    _restockTime(restockTime)
    {
        _lineEditing = true;
    }

    void Reception::start()
    {
        std::string input;

        if (_lineEditing)
            LineEditing::configureTerminal();
        std::clog << "Starting reception" << std::endl;
        while (true) {
            input = LineEditing::readInput();
            for (auto &kitchen : _kitchens)
                kitchen->handle();
            removeClosedKitchens();
            processCommand(input);
            for (auto &kitchen : _kitchens)
                kitchen->handle();
            removeClosedKitchens();
            if (_breakLoop)
                break;
        }
        if (_lineEditing)
            LineEditing::restoreTerminal();
        std::clog << "Exiting reception..." << std::endl;
    }

    void Reception::processCommand(const std::string &command)
    {
        std::istringstream iss(command);
        std::string action;
        iss >> action;

        static std::unordered_map<std::string, std::function<void()>> actions = {
            {"status", [this](){ displayKitchensStatus(); }},
            {"clear", [](){ std::cout << "\033[2J\033[1;1H"; }},
            {"exit", [this](){ _breakLoop = true; }}
        };
        if (actions.contains(command))
            actions[command]();
        else
            placeOrder(command);
    }

    void Reception::displayKitchensStatus() const
    {
        int i = 0;
        std::array<size_t, 9UL> ingredients;

        if (_kitchens.empty()) {
            std::clog << "There is no kitchens... exit" << std::endl;
            return;
        }
        std::clog << "Displaying kitchens status..." << std::endl;

        size_t ongoingOrders = 0;

        for (auto &kitchen : _kitchens) {
            ongoingOrders = kitchen->getOngoingOrders();

            std::clog << "----------------------------------" << std::endl;
            std::clog << "         Kitchen number " << i << std::endl;
            std::clog << "        cook in service : " << ((ongoingOrders <= (size_t)_numCooksPerKitchen) ? ongoingOrders : _numCooksPerKitchen) << std::endl;
            std::clog << "       stocks of ingredient :" << std::endl;
            ingredients = kitchen->getIngredientStock();;
            displayIngredients(ingredients);
            std::clog << "----------------------------------" << std::endl;
            i++;
        }
    }

    void Reception::displayIngredients(std::array<size_t, 9UL> ingredients) const
    {
        std::vector<std::string> ingredientsName = {
            "Dough",       // 0000000000000001
            "Tomato",      // 0000000000000010
            "Gruyere",     // 0000000000000100
            "Ham",         // 0000000000001000
            "Mushrooms",   // 0000000000010000
            "Steak",       // 0000000000100000
            "Eggplant",    // 0000000001000000
            "GoatCheese",  // 0000000010000000
            "ChiefLove"    // 0000000100000000
        };

        for (size_t i = 0; i < NUM_INGREDIENTS; ++i)
            std::clog << ingredientsName[i] << ": " << ingredients[i] << std::endl;
    }

    void Reception::placeOrder(const std::string &orderString)
    {
        std::istringstream iss(orderString);
        std::string order;

        while (std::getline(iss, order, ';'))
            processIndividualOrder(trim(order));
        dispatchKitchen();
    }

    void Reception::processIndividualOrder(const std::string &order)
    {
        std::istringstream iss(order);
        std::string type;
        std::string size;
        int quantity;
        char separator;

        if (!(iss >> type >> size >> separator >> quantity) || separator != 'x') {
            std::cerr << "Invalid order format: " << order << std::endl;
            return;
        }
        PizzaType pType = getPizzaType(type);
        PizzaSize pSize = getPizzaSize(size);
        if (pType == PizzaType::NoneType || pSize == PizzaSize::NoneSize)
            return;
        std::string newOrder = type + ":" + size;
        for (int i = 0; i < quantity; i++)
            _orders.push_back(newOrder);

    }

    PizzaType Reception::getPizzaType(std::string type)
    {
        return PizzaFactory::convertToPizzaType(type);
    }

    PizzaSize Reception::getPizzaSize(std::string size)
    {
        return PizzaFactory::convertToPizzaSize(size);
    }

    void Reception::dispatchKitchen()
    {
        plazza::Kitchen *lowest_kitchen;
        size_t lowest;

        if (_orders.empty())
            return;
        std::clog << "We are dispatching the pizzas" << std::endl;
        for (auto &order : _orders) {
            lowest = (size_t)_numCooksPerKitchen * 2;
            for (auto &kitchen : _kitchens) {
                size_t onGoing = kitchen->getOngoingOrders();
                if (onGoing < lowest) {
                    lowest = onGoing;
                    lowest_kitchen = kitchen.get();
                    break;
                }
            }
            if (lowest < (size_t)_numCooksPerKitchen * 2)
                lowest_kitchen->tryAddOrder(order);
            else {
                _kitchens.push_back(std::make_unique<Kitchen>(static_cast<size_t>(_numCooksPerKitchen), _multiplier, static_cast<size_t>(_restockTime)));
                _kitchens.back()->tryAddOrder(order);
            }
        }
        _orders.clear();
    }

    std::string Reception::trim(const std::string &str)
    {
        auto start = std::find_if_not(str.begin(), str.end(), [](int c) {
            return std::isspace(static_cast<unsigned char>(c));
        });

        auto end = std::find_if_not(str.rbegin(), str.rend(), [](int c) {
            return std::isspace(static_cast<unsigned char>(c));
        }).base();

        return (start < end) ? std::string(start, end) : std::string();
    }

    void Reception::removeClosedKitchens()
    {
        std::vector<std::unique_ptr<Kitchen>> _kitchensTemp;

        for (auto &kitchen : _kitchens)
            if (!kitchen->shouldBeClosed())
                _kitchensTemp.push_back(std::move(kitchen));
        _kitchens.clear();
        for (auto &kitchen : _kitchensTemp)
            _kitchens.push_back(std::move(kitchen));
    }
}
