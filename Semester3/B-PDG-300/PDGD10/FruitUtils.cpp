/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD10-florent.guittre
** File description:
** FruitUtils.cpp
*/

#include "Lemon.hpp"
#include "ABerry.hpp"
#include "FruitUtils.hpp"

void FruitUtils::sort(FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus,
                      FruitBox &berry)
{
    IFruit *current;
    int len = unsorted.nbFruits();

    for (int i = 0; i < len; i++) {
        current = unsorted.popFruit();
        if (!lemon.isFull() && dynamic_cast<Lemon *>(current) != nullptr) {
            lemon.pushFruit(current);
            continue;
        }
        if (!citrus.isFull() && dynamic_cast<Lemon *>(current) == nullptr &&
            dynamic_cast<ACitrus *>(current) != nullptr) {
            citrus.pushFruit(current);
            continue;
        }
        if (!berry.isFull() && dynamic_cast<ABerry *>(current) != nullptr) {
            berry.pushFruit(current);
            continue;
        }
        unsorted.pushFruit(current);
    }
}
