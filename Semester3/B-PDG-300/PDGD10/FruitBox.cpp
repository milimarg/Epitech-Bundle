/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD10-florent.guittre
** File description:
** FruitBox.cpp
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(unsigned int size)
    : _size(size) {}

FruitBox::~FruitBox()
{
    IFruit *fruit;

    while (nbFruits() != 0) {
        fruit = popFruit();
        delete fruit;
    }
}

unsigned int FruitBox::getSize() const
{
    return _size;
}

unsigned int FruitBox::nbFruits() const
{
    return box.size();
}

bool FruitBox::pushFruit(IFruit *fruit)
{
    if (nbFruits() >= getSize() ||
    std::find(box.begin(), box.end(), fruit) != box.end()) {
        return false;
    }
    box.push_back(fruit);
    return true;
}

IFruit *FruitBox::popFruit()
{
    IFruit *fruit;

    if (nbFruits() == 0) {
        return nullptr;
    }
    fruit = box.front();
    box.pop_front();
    return fruit;
}

const std::deque<IFruit *> &FruitBox::getBox() const
{
    return box;
}

bool FruitBox::isFull() const
{
    return nbFruits() >= getSize();
}
