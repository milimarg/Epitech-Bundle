/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD09-florent.guittre
** File description:
** Knight.cpp
*/

#include "Knight.hpp"

Knight::Knight(const std::string &name, int power)
    : Peasant(name, power)
{
    std::cout << _name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << _name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    static const int cost = 10;
    static const int damage = 20;

    if (!useTechnique(cost, 0, _name + " strikes with his sword.")) {
        return 0;
    }
    return damage;
}

int Knight::special()
{
    static const int cost = 30;
    static const int damage = 50;

    if (!useTechnique(cost, 0, _name + " impales his enemy.")) {
        return 0;
    }
    return damage;
}

void Knight::rest()
{
    static const int cost = 0;
    static const int damage = 0;

    useTechnique(cost, damage, _name + " eats.");
    if (_health == 0) {
        return;
    }
    setPower(getPower() + 50);
}
