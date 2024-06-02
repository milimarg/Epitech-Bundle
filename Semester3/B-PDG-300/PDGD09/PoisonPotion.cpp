/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD09-florent.guittre
** File description:
** PoisonPotion.cpp
*/

#include "PoisonPotion.hpp"

PoisonPotion::PoisonPotion()
{
    healthToAdd = -50;
    powerToAdd = 0;
}

PoisonPotion::~PoisonPotion() {}

int PoisonPotion::getHealth() const
{
    return healthToAdd;
}

int PoisonPotion::getPower() const
{
    return powerToAdd;
}
