/*
** EPITECH PROJECT, 2024
** preparing-plazza
** File description:
** PizzaFactory
*/

#ifndef PIZZAFACTORY_HPP_
    #define PIZZAFACTORY_HPP_

    #include <memory>
    #include <unordered_map>
    #include <functional>
    #include "IPizza.hpp"
    #include "Error.hpp"

namespace plazza
{
    class PizzaFactory {
        public:
            static PizzaFactory&getInstance();

            std::unique_ptr<IPizza> createPizza(PizzaType type, PizzaSize size);

            static PizzaType convertToPizzaType(const std::string &type);
            static PizzaSize convertToPizzaSize(const std::string &size);

        private:
            PizzaFactory();
            ~PizzaFactory() = default;
            PizzaFactory(const PizzaFactory&) = delete;
            PizzaFactory &operator=(const PizzaFactory&) = delete;

            void registerPizzaType(PizzaType type, std::function<std::unique_ptr<IPizza>(PizzaSize)> creator);

            std::unordered_map<PizzaType, std::function<std::unique_ptr<IPizza>(PizzaSize)>> _pizzaCreators;
    };
}

#endif /* !PIZZAFACTORY_HPP_ */
