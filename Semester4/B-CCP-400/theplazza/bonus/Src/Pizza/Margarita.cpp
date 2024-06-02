/*
** EPITECH PROJECT, 2024
** preparing-plazza
** File description:
** Margarita
*/

#include "Margarita.hpp"

namespace plazza
{
    Margarita::Margarita(PizzaSize size)
        : APizza(PizzaType::Margarita, size, 1)
    {
        addIngredients(
            PizzaIngredient::Dough,
            PizzaIngredient::Tomato,
            PizzaIngredient::Gruyere,
            PizzaIngredient::Ham,
            PizzaIngredient::Mushrooms
        );
    }
}
