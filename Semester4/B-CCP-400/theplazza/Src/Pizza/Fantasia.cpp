/*
** EPITECH PROJECT, 2024
** preparing-plazza
** File description:
** Fantasia
*/

#include "Fantasia.hpp"

namespace plazza
{
    Fantasia::Fantasia(PizzaSize size)
        : APizza(PizzaType::Fantasia, size, 2)
    {
        addIngredients(
            PizzaIngredient::Dough,
            PizzaIngredient::Tomato,
            PizzaIngredient::Eggplant,
            PizzaIngredient::GoatCheese,
            PizzaIngredient::ChiefLove
        );
    }
}
