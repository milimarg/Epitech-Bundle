/*
** EPITECH PROJECT, 2024
** preparing-plazza
** File description:
** Americana
*/

#include "Americana.hpp"

namespace plazza
{
    Americana::Americana(PizzaSize size)
        : APizza(PizzaType::Americana, size, 2)
    {
        addIngredients(
            PizzaIngredient::Dough,
            PizzaIngredient::Tomato,
            PizzaIngredient::Gruyere,
            PizzaIngredient::Steak
        );
    }
}
