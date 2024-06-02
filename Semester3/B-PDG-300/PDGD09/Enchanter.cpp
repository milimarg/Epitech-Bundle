/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD09-florent.guittre
** File description:
** Enchanter.cpp
*/

#include "Enchanter.hpp"

Enchanter::Enchanter(const std::string &name, int power)
    : Peasant(name, power)
{
    std::cout << _name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << _name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    static const int cost = 0;
    static const int damage = 0;

    if (!useTechnique(cost, 0, _name + " doesn't know how to fight.")) {
        return 0;
    }
    return damage;
}

int Enchanter::special()
{
    static const int cost = 50;
    static const int damage = 99;

    if (!useTechnique(cost, 0, _name + " casts a fireball.")) {
        return 0;
    }
    return damage;
}

void Enchanter::rest()
{
    static const int cost = 0;
    static const int damage = 0;

    useTechnique(cost, damage, _name + " meditates.");
    if (_health == 0) {
        return;
    }
    setPower(getPower() + 100);
}
