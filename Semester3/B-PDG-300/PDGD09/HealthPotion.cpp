/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD09-florent.guittre
** File description:
** HealthPotion.cpp
*/

#include "HealthPotion.hpp"

HealthPotion::HealthPotion()
{
    healthToAdd = 50;
    powerToAdd = 0;
}

HealthPotion::~HealthPotion() {}

int HealthPotion::getHealth() const
{
    return healthToAdd;
}

int HealthPotion::getPower() const
{
    return powerToAdd;
}
