/*
** EPITECH PROJECT, 2024
** preparing-plazza
** File description:
** APizza
*/

#include "APizza.hpp"

namespace plazza
{
    APizza::APizza(PizzaType type, PizzaSize size, double bakeTime)
        : _type(type), _size(size), _bakeTime(bakeTime)
    {
    }

    PizzaType APizza::getType() const
    {
        return _type;
    }

    PizzaSize APizza::getSize() const
    {
        return _size;
    }

    std::string APizza::getTypeStr() const
    {
        static std::unordered_map<PizzaType, std::string> typeMap = {
            {PizzaType::Regina, "regina"},
            {PizzaType::Margarita, "margarita"},
            {PizzaType::Americana, "americana"},
            {PizzaType::Fantasia, "fantasia"}
        };
        if (!typeMap.contains(_type))
            return "";
        return typeMap[_type];
    }

    std::string APizza::getSizeStr() const
    {
        static std::unordered_map<PizzaSize, std::string> sizeMap = {
            {PizzaSize::Small, "s"},
            {PizzaSize::Medium, "m"},
            {PizzaSize::Large, "l"},
            {PizzaSize::XLarge, "xl"},
            {PizzaSize::XXLarge, "xxl"}
        };
        if (!sizeMap.contains(_size))
            return "";
        return sizeMap[_size];
    }

    double APizza::getBakeTime(double multiplier) const
    {
        return _bakeTime * multiplier;
    }

    void APizza::addIngredient(PizzaIngredient ingredient)
    {
        size_t index = static_cast<size_t>(std::log2(static_cast<double>(ingredient)));

        _ingredients.set(index);
    }

    bool APizza::hasIngredient(PizzaIngredient ingredient) const
    {
        size_t index = static_cast<size_t>(std::log2(static_cast<double>(ingredient)));

        return _ingredients.test(index);
    }

    std::bitset<NUM_INGREDIENTS> &APizza::getIngredients()
    {
        return _ingredients;
    }
}
