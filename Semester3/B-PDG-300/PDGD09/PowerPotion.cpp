/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD09-florent.guittre
** File description:
** PowerPotion.cpp
*/

#include "PowerPotion.hpp"

PowerPotion::PowerPotion()
{
    healthToAdd = 0;
    powerToAdd = 50;
}

PowerPotion::~PowerPotion() {}

int PowerPotion::getHealth() const
{
    return healthToAdd;
}

int PowerPotion::getPower() const
{
    return powerToAdd;
}
