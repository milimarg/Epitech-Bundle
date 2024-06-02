/*
** EPITECH PROJECT, 2024
** preparing-plazza
** File description:
** Regina
*/

#include "Regina.hpp"

namespace plazza
{
    Regina::Regina(PizzaSize size)
        : APizza(PizzaType::Regina, size, 2)
    {
        addIngredients(
            PizzaIngredient::Dough,
            PizzaIngredient::Tomato,
            PizzaIngredient::Gruyere
        );
    }
}
