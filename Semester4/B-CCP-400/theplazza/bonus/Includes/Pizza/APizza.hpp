/*
** EPITECH PROJECT, 2024
** preparing-plazza
** File description:
** APizza
*/

#ifndef APIZZA_HPP_
    #define APIZZA_HPP_
    #include "IPizza.hpp"
    #include <unordered_map>

namespace plazza
{
    class APizza : public IPizza {
        public:
            APizza(PizzaType type, PizzaSize size, double bakeTime);
            PizzaType getType() const override;
            PizzaSize getSize() const override;

            std::string getTypeStr() const override;
            std::string getSizeStr() const override;

            double getBakeTime(double multiplier) const override;

            void addIngredient(PizzaIngredient ingredient);

            template<typename... Args>
            void addIngredients(Args... ingredients);

            bool hasIngredient(PizzaIngredient ingredient) const;
            std::bitset<NUM_INGREDIENTS> &getIngredients() override;

        private:
            PizzaType _type;
            PizzaSize _size;
            double _bakeTime;
            std::bitset<NUM_INGREDIENTS> _ingredients;
    };

    template<typename... Args>
    void APizza::addIngredients(Args... ingredientsToAdd)
    {
        (addIngredient(ingredientsToAdd), ...);
    }
}

#endif /* !APIZZA_HPP_ */
