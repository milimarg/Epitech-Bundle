/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD10-florent.guittre
** File description:
** AFruit.cpp
*/

#include "AFruit.hpp"

AFruit::AFruit()
    : IFruit() {}

AFruit::~AFruit() {}

unsigned int AFruit::getVitamins() const
{
    return isPeeled() ? vitamins : 0;
}

std::string AFruit::getName() const
{
    return name;
}

bool AFruit::isPeeled() const
{
    return peelStatus;
}

void AFruit::peel()
{
    if (!peelStatus) {
        peelStatus = !peelStatus;
    }
}
