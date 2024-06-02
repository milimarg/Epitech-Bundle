/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD09-florent.guittre
** File description:
** Priest.cpp
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int power)
    : Peasant(name, power), Enchanter(name, power)
{
    std::cout << _name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << _name << " finds peace." << std::endl;
}

void Priest::rest()
{
    static const int cost = 0;
    static const int damage = 0;

    useTechnique(cost, damage, _name + " prays.");
    if (_health == 0) {
        return;
    }
    setPower(getPower() + 100);
    setHp(getHp() + 100);
    return;
}
