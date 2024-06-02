/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
    #define KITCHEN_HPP_

    #include "ThreadPool.hpp"
    #include <deque>
    #include "Process.hpp"
    #include <vector>
    #include <atomic>
    #include <iostream>
    #include <thread>
    #include <memory>
    #include "NamedPipe.hpp"
    #include <cstdlib>
    #include "PizzaFactory.hpp"
    #include "APizza.hpp"
    #include "RaylibWrapper.hpp"

namespace plazza
{
    class Kitchen;

    class KitchenState {
        public:
            virtual ~KitchenState() {}
            virtual void handle(Kitchen &kitchen) = 0;
    };

    class ReceptionState : public KitchenState {
        public:
            void handle(Kitchen &kitchen) override;
    };

    class CookingState : public KitchenState {
        public:
            void handle(Kitchen &kitchen) override;
        private:
            float _timeBank = 0.0f;
    };

    class Kitchen {
        public:
            Kitchen(size_t numCooks, double cookingTimeMultiplier, size_t ingredientRefillTimer);
            ~Kitchen();

            void start();
            void stop();
            bool tryAddOrder(const std::string &order);
            void changeState(std::unique_ptr<KitchenState> newState);
            std::deque<std::string> &getOrders();
            NamedPipe &getParentToChildPipe();
            NamedPipe &getChildToParentPipe();
            void decrementOngoingorders();
            size_t getWorkingCooks() const;
            std::unique_ptr<ThreadPool> &getThreadPool();
            std::array<size_t, NUM_INGREDIENTS> &getIngredientStock();
            Mutex &getIngredientStockMutex();
            size_t getOngoingOrders() const;
            std::chrono::steady_clock::time_point &getLastRefillTime();
            std::chrono::steady_clock::time_point &getLastActionTime();
            size_t getIngredientRefillTimer() const;
            double getCookingTimeMultiplier() const;
            std::unique_ptr<Process> &getProcess();
            ConditionalVariable &getConditionVariable();
            Mutex &getPrintMutex();
            void handle();
            bool shouldBeClosed() const;
            void setPosition(Vector3 newPosition);
            Vector3 getPosition() const;

        private:
            void run();

            std::unique_ptr<ThreadPool> _threadPool;
            std::deque<std::string> _orders;
            std::atomic<bool> _running;
            size_t _numCooks;
            double _cookingTimeMultiplier;
            size_t _ingredientRefillTimer;
            std::unique_ptr<Process> _process;
            std::unique_ptr<KitchenState> _state;
            size_t _ongoingOrders;
            NamedPipe _parentToChildPipe;
            NamedPipe _childToParentPipe;
            std::array<size_t, NUM_INGREDIENTS> _ingredientStock;
            Mutex _ingredientStockMutex;
            std::chrono::steady_clock::time_point _lastRefillTime;
            std::chrono::steady_clock::time_point _lastActionTime; // ? does it count when a cook want to cook but he is waiting for ingredients?
            ConditionalVariable _conditionVariable;
            Mutex _printMutex;
            bool _shouldBeClosed;
            Vector3 _position;
    };
}

#endif /* KITCHEN_HPP_ */
