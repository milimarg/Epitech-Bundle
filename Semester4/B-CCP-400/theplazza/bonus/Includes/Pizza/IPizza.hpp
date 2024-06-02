/*
** EPITECH PROJECT, 2024
** preparing-plazza
** File description:
** IPizza
*/

#ifndef IPIZZA_H
    #define IPIZZA_H
    #include <iostream>
    #include <bitset>
    #include <stdint.h>
    #include <cmath>

namespace plazza
{
    enum class PizzaType : uint32_t {
        NoneType = 0UL,
        Regina = 1UL << 0,
        Margarita = 1UL << 1,
        Americana = 1UL << 2,
        Fantasia = 1UL << 3,
    };

    enum class PizzaSize : uint32_t {
        NoneSize = 0UL,
        Small = 1UL << 0,
        Medium = 1UL << 1,
        Large = 1UL << 2,
        XLarge = 1UL << 3,
        XXLarge = 1UL << 4
    };

    enum class PizzaIngredient : uint64_t {
        Dough = 1ULL << 0,       // 0000000000000001
        Tomato = 1ULL << 1,      // 0000000000000010
        Gruyere = 1ULL << 2,     // 0000000000000100
        Ham = 1ULL << 3,         // 0000000000001000
        Mushrooms = 1ULL << 4,   // 0000000000010000
        Steak = 1ULL << 5,       // 0000000000100000
        Eggplant = 1ULL << 6,    // 0000000001000000
        GoatCheese = 1ULL << 7,  // 0000000010000000
        ChiefLove = 1ULL << 8    // 0000000100000000
    };

    constexpr size_t NUM_INGREDIENTS = 9;

    class IPizza {
        public:
            virtual ~IPizza() {}
            virtual PizzaType getType() const = 0;
            virtual PizzaSize getSize() const = 0;
            virtual std::string getTypeStr() const = 0;
            virtual std::string getSizeStr() const = 0;
            virtual double getBakeTime(double multiplier) const = 0;
            virtual std::bitset<NUM_INGREDIENTS> &getIngredients() = 0;
    };
}

#endif // IPIZZA_H
