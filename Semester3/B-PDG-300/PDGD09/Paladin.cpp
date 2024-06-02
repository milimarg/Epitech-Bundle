/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD09-florent.guittre
** File description:
** Paladin.cpp
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int power)
    : Peasant(name, power), Knight(name, power), Enchanter(name, power), Priest(name, power)
{
    std::cout << _name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << _name << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return Knight::attack();
}

int Paladin::special()
{
    return Enchanter::special();
}

void Paladin::rest()
{
    Priest::rest();
}
