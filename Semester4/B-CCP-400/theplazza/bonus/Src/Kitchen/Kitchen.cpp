/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** Kitchen
*/

#include "Kitchen.hpp"
#include <algorithm>
#include <sstream>

namespace plazza
{
    Kitchen::Kitchen(size_t numCooks, double cookingTimeMultiplier, size_t ingredientRefillTimer)
        : _threadPool(nullptr),
          _running(true),
          _numCooks(numCooks),
          _cookingTimeMultiplier(cookingTimeMultiplier),
          _ingredientRefillTimer(ingredientRefillTimer),
          _process(std::make_unique<Process>()),
          _state(std::make_unique<ReceptionState>()),
          _ongoingOrders(0),
          _parentToChildPipe(std::string("/tmp/plazza_parent_to_child_") + std::to_string(rand())),
          _childToParentPipe(std::string("/tmp/plazza_child_to_parent_") + std::to_string(rand())),
          _lastRefillTime(std::chrono::steady_clock::now()),
          _lastActionTime(std::chrono::steady_clock::now()),
          _shouldBeClosed(false)
    {
        _ingredientStock.fill(5);
        _process->forkProcess();
        if (_process->isChild()) {
            _parentToChildPipe.openRead();
            _childToParentPipe.openWrite();
            _state = std::make_unique<CookingState>();
            _threadPool = std::make_unique<ThreadPool>(_numCooks);
            _threadPool->start();
            run();
        } else {
            _parentToChildPipe.openWrite();
            _childToParentPipe.openRead();
        }
        // TODO: add error handling in << and >> operators to check for issues
        // ? add error handling for failing to open write / read?
    }

    Kitchen::~Kitchen()
    {
        stop();
    }

    void Kitchen::start()
    {
        _running = true;
    }

    void Kitchen::stop()
    {
        _running = false;
        _shouldBeClosed = true;
    }

    bool Kitchen::tryAddOrder(const std::string &order)
    {
        if (_ongoingOrders > 2 * _numCooks)
            return false;
        _orders.push_back(order);
        ++_ongoingOrders;

        return true;
    }

    void Kitchen::changeState(std::unique_ptr<KitchenState> newState)
    {
        _state = std::move(newState);
    }

    void Kitchen::run()
    {
        while (_running)
            handle();
    }

    std::deque<std::string> &Kitchen::getOrders()
    {
        return _orders;
    }

    NamedPipe &Kitchen::getParentToChildPipe()
    {
        return _parentToChildPipe;
    }

    NamedPipe &Kitchen::getChildToParentPipe()
    {
        return _childToParentPipe;
    }

    void Kitchen::decrementOngoingorders()
    {
        --_ongoingOrders;
    }

    size_t Kitchen::getWorkingCooks() const
    {
        return std::min(_numCooks, _ongoingOrders);
    }

    std::unique_ptr<ThreadPool> &Kitchen::getThreadPool()
    {
        return _threadPool;
    }

    std::array<size_t, NUM_INGREDIENTS> &Kitchen::getIngredientStock()
    {
        return _ingredientStock;
    }

    Mutex &Kitchen::getIngredientStockMutex()
    {
        return _ingredientStockMutex;
    }

    size_t Kitchen::getOngoingOrders() const
    {
        return _ongoingOrders;
    }

    std::chrono::steady_clock::time_point &Kitchen::getLastRefillTime()
    {
        return _lastRefillTime;
    }

    std::chrono::steady_clock::time_point &Kitchen::getLastActionTime()
    {
        return _lastActionTime;
    }

    size_t Kitchen::getIngredientRefillTimer() const
    {
        return _ingredientRefillTimer;
    }

    double Kitchen::getCookingTimeMultiplier() const
    {
        return _cookingTimeMultiplier;
    }

    std::unique_ptr<Process> &Kitchen::getProcess()
    {
        return _process;
    }

    ConditionalVariable &Kitchen::getConditionVariable()
    {
        return _conditionVariable;
    }

    Mutex &Kitchen::getPrintMutex()
    {
        return _printMutex;
    }

    void Kitchen::handle()
    {
        _state->handle(*this);
    }

    void ReceptionState::handle(Kitchen &kitchen)
    {
        std::deque<std::string> &orders = kitchen.getOrders();

        if (!orders.empty() || kitchen.getWorkingCooks() != 0)
            kitchen.getLastActionTime() = std::chrono::steady_clock::now();

        for (auto &order : orders)
            kitchen.getParentToChildPipe() << order << ";";

        orders.clear();

        auto currentTime = std::chrono::steady_clock::now();
        auto timeSinceLastAction = std::chrono::duration_cast<std::chrono::seconds>(currentTime - kitchen.getLastActionTime());
        if (timeSinceLastAction >= std::chrono::seconds(5)) {
            kitchen.stop();
            pid_t childPID = kitchen.getProcess()->getPID();
            if (childPID > 0)
                kill(childPID, SIGKILL);
        }

        while (true) {
            std::vector<std::string> messages;
            kitchen.getChildToParentPipe() >> messages;
            if (messages.empty())
                break;
            for (auto &message : messages) {
                if (message.find("Pizza cooked") != std::string::npos) {
                    kitchen.decrementOngoingorders();
                    continue;
                }
                if (message.find("Ingredient stocks-") != std::string::npos) {
                    size_t pos = message.find("Ingredient stocks-");
                    if (pos == std::string::npos)
                        continue;

                    std::array<size_t, NUM_INGREDIENTS> &stocks = kitchen.getIngredientStock();

                    std::string stockValues = message.substr(pos + 18);

                    std::istringstream iss(stockValues);
                    size_t value;
                    size_t index = 0;
                    while (iss >> value && index < NUM_INGREDIENTS) {
                        stocks[index] = value;
                        ++index;
                    }
                    continue;
                }
            }
        }
    }

    void CookingState::handle(Kitchen &kitchen)
    {
        NamedPipe &pipe = kitchen.getChildToParentPipe();

        auto currentTime = std::chrono::steady_clock::now();
        auto timeSinceLastRefill = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - kitchen.getLastRefillTime());
        double waitTime = std::chrono::milliseconds(kitchen.getIngredientRefillTimer()).count();
        _timeBank += timeSinceLastRefill.count();
        if (_timeBank >= waitTime) {
            {
                ScopedLock lock(kitchen.getIngredientStockMutex());

                std::string message = "Ingredient stocks-";
                for (auto &stock : kitchen.getIngredientStock()) {
                    ++stock;
                    message += " " + std::to_string(stock);
                }
                pipe << message << ";";
            }
            _timeBank -= waitTime;
        }
        kitchen.getLastRefillTime() = currentTime;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::vector<std::string> orders;
        kitchen.getParentToChildPipe() >> orders;

        for (const auto &order : orders) {
            size_t pos = order.find(':');
            if (pos == std::string::npos) {
                std::cerr << "Invalid order format: " << order << std::endl;
                continue;
            }

            std::string type = order.substr(0, pos);
            std::string size = order.substr(pos + 1);

            {
                ScopedLock lock(kitchen.getPrintMutex());
                // std::clog << "sending a new order!" << std::endl;
            }

            // TODO: check why the 2nd task does not seem to be starting follownig the end of the first one
            kitchen.getThreadPool()->addTask(
                [&kitchen, type, size]() {
                    {
                        ScopedLock lock(kitchen.getPrintMutex());
                        // std::clog << "executing a new order!" << std::endl;
                    }

                    std::unique_ptr<IPizza> pizza = PizzaFactory::getInstance().createPizza(
                        PizzaFactory::convertToPizzaType(type),
                        PizzaFactory::convertToPizzaSize(size)
                    );

                    if (!pizza) {
                        std::cerr << "Could not create pizza" << std::endl;
                        return;
                    }

                    auto ingredients = pizza->getIngredients();

                    {
                        ScopedLock lock(kitchen.getIngredientStockMutex());
                        for (size_t i = 0; i < NUM_INGREDIENTS; ++i) {
                            if (ingredients.test(i)) {
                                kitchen.getIngredientStockMutex().unlock();
                                while (kitchen.getIngredientStock()[i] == 0) {
                                    kitchen.getConditionVariable().wait(kitchen.getIngredientStockMutex(), [&kitchen, i] { return kitchen.getIngredientStock()[i] > 0; });
                                }
                                --kitchen.getIngredientStock()[i];
                                kitchen.getIngredientStockMutex().lock();
                            }
                        }
                    }

                    std::chrono::duration<double> preciseCookingTime = std::chrono::duration<double>(
                        pizza->getBakeTime(kitchen.getCookingTimeMultiplier())
                    );
                    // std::clog << "cooking will take: " << preciseCookingTime.count() << std::endl;
                    std::this_thread::sleep_for(preciseCookingTime);

                    // {
                    //     ScopedLock lock(kitchen.getPrintMutex());
                    //     std::clog << pizza->getTypeStr() << " - " << pizza->getSizeStr() << " cooked!" << std::endl;
                    // }

                    kitchen.getChildToParentPipe() << "Pizza cooked" << ";";
                }
            );
        }
    }

    bool Kitchen::shouldBeClosed() const
    {
        return _shouldBeClosed;
    }

    void Kitchen::setPosition(Vector3 newPosition)
    {
        _position = newPosition;
    }

    Vector3 Kitchen::getPosition() const
    {
        return _position;
    }
}
