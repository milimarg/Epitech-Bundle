/*
** EPITECH PROJECT, 2024
** preparing-plazza
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
    #define RECEPTION_HPP_
    #include <string>
    #include <vector>
    #include <unordered_map>
    #include <functional>
    #include <iostream>
    #include <sstream>
    #include <algorithm>
    #include "IPizza.hpp"
    #include "Kitchen.hpp"
    #include "Error.hpp"
    #include "PizzaFactory.hpp"
    #include "LineEditing.hpp"

namespace plazza
{
    class Reception {
        public:
            static Reception &getInstance(double multiplier = 0.0f, int numCooksPerKitchen = 0, int restockTime = 0);

            void start();

        private:
            Reception(const Reception &) = delete;
            Reception &operator=(const Reception &) = delete;
            Reception(double multiplier, int numCooksPerKitchen, int restockTime);
            void processCommand(const std::string &command);
            void placeOrder(const std::string &orderString);
            void displayKitchensStatus() const;
            void displayIngredients(std::array<size_t, 9UL> ingredients) const;
            PizzaType getPizzaType(std::string type);
            PizzaSize getPizzaSize(std::string size);
            void dispatchKitchen();
            void processIndividualOrder(const std::string &order);
            std::string trim(const std::string &str);
            void removeClosedKitchens();

            bool _breakLoop;
            double _multiplier;
            int _numCooksPerKitchen;
            int _restockTime;
            bool _lineEditing;
            std::vector<std::string> _orders;
            std::unordered_map<int, int> _kitchenStatus;
            std::vector<std::unique_ptr<Kitchen>> _kitchens;
    };
}

#endif /* !RECEPTION_HPP_ */
