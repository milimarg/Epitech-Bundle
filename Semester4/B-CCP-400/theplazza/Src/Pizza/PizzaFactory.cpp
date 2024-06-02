/*
** EPITECH PROJECT, 2024
** preparing-plazza
** File description:
** PizzaFactory
*/

#include "PizzaFactory.hpp"
#include "Margarita.hpp"
#include "Regina.hpp"
#include "Americana.hpp"
#include "Fantasia.hpp"

namespace plazza
{
    PizzaFactory &PizzaFactory::getInstance()
    {
        static PizzaFactory instance;
        return instance;
    }

    PizzaFactory::PizzaFactory()
    {
        registerPizzaType(PizzaType::Margarita, [](PizzaSize size) { return std::make_unique<Margarita>(size); });
        registerPizzaType(PizzaType::Regina, [](PizzaSize size) { return std::make_unique<Regina>(size); });
        registerPizzaType(PizzaType::Americana, [](PizzaSize size) { return std::make_unique<Americana>(size); });
        registerPizzaType(PizzaType::Fantasia, [](PizzaSize size) { return std::make_unique<Fantasia>(size); });
    }

    std::unique_ptr<IPizza> PizzaFactory::createPizza(PizzaType type, PizzaSize size)
    {
        auto it = _pizzaCreators.find(type);
        if (it == _pizzaCreators.end())
            throw Error("Type not recognized - " + std::to_string(static_cast<int>(type)));

        return it->second(size);
    }

    void PizzaFactory::registerPizzaType(PizzaType type, std::function<std::unique_ptr<IPizza>(PizzaSize)> creator)
    {
        _pizzaCreators[type] = creator;
    }

    PizzaType PizzaFactory::convertToPizzaType(const std::string &type)
    {
        std::string temp = type;
        static std::unordered_map<std::string, PizzaType> typeMap = {
            {"regina", PizzaType::Regina},
            {"margarita", PizzaType::Margarita},
            {"americana", PizzaType::Americana},
            {"fantasia", PizzaType::Fantasia}
        };
        std::transform(temp.begin(), temp.end(), temp.begin(),
            [](unsigned char c) {
                return std::tolower(c);
            }
        );
        if (!typeMap.contains(temp)) {
            std::cerr << "Wrong type " << type << std::endl;
            return PizzaType::NoneType;
        }
        return typeMap[temp];
    }

    PizzaSize PizzaFactory::convertToPizzaSize(const std::string &size)
    {
        std::string temp = size;
        static std::unordered_map<std::string, PizzaSize> sizeMap = {
            {"s", PizzaSize::Small},
            {"m", PizzaSize::Medium},
            {"l", PizzaSize::Large},
            {"xl", PizzaSize::XLarge},
            {"xxl", PizzaSize::XXLarge}
        };
        std::transform(temp.begin(), temp.end(), temp.begin(),
            [](unsigned char c) {
                return std::tolower(c);
            }
        );
        if (!sizeMap.contains(temp)) {
            std::cerr << "Wrong size: " << size << std::endl;
            return PizzaSize::NoneSize;
        }
        return sizeMap[temp];
    }
}
