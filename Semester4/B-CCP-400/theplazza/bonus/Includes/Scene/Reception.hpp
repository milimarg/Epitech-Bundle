/*
** EPITECH PROJECT, 2024
** Epitech-Jam-Flamme
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
    #define RECEPTION_HPP_
    #include "AScene.hpp"
    #include "RaylibWrapper.hpp"
    #include <cmath>
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

namespace plazza
{
    class Reception : public AScene {
        public:
            Reception(double multiplier = 0.0f, int numCooksPerKitchen = 0, int restockTime = 0);
            ~Reception();

            void events() override;
            void update(float deltaTime) override;
            void render() override;

        private:
            Camera3D _camera3D;
            float _timeBank;
            bool _isStop;
            bool _writingOrder;

            std::string _input;
            double _multiplier;
            int _numCooksPerKitchen;
            int _restockTime;
            std::vector<std::string> _orders;
            std::unordered_map<int, int> _kitchenStatus;
            std::vector<std::unique_ptr<Kitchen>> _kitchens;

            void createCamera();
            void drawKitchens();
            void updateCamera(float deltaTime);

            void initializeKitchens();

            void processCommand(const std::string &command);
            void placeOrder(const std::string &orderString);
            PizzaType getPizzaType(std::string type);
            PizzaSize getPizzaSize(std::string size);
            void dispatchKitchen();
            void processIndividualOrder(const std::string &order);
            std::string trim(const std::string &str);
            void removeClosedKitchens();
    };
}

#endif /* !RECEPTION_HPP_ */
