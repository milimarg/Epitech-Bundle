/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD08-florent.guittre
** File description:
** Droid.cpp
*/

#include "Droid.hpp"

Droid::Droid(std::string serial, size_t energy, size_t attack, size_t toughness,
             std::string status)
    : _serial(serial), Energy(energy), Attack(attack), Toughness(toughness),
    Status(new std::string(status))
{
    std::cout << "Droid '" << _serial << "' Activated" << std::endl;
}

Droid::Droid(const Droid &droid)
    : _serial(droid._serial), Energy(droid.Energy), Attack(droid.Attack),
    Toughness(droid.Toughness)
{
    Status = new std::string(*droid.Status);
    std::cout << "Droid '" << _serial << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << _serial << "' Destroyed" << std::endl;
    delete Status;
}

std::string Droid::getId() const
{
    return _serial;
}

void Droid::setId(std::string serial)
{
    _serial = serial;
}

size_t Droid::getEnergy() const
{
    return Energy;
}

void Droid::setEnergy(size_t energy)
{
    Energy = energy;
    if (Energy > 100) {
        Energy = 100;
    }
}

size_t Droid::getAttack() const
{
    return Attack;
}

size_t Droid::getToughness() const
{
    return Toughness;
}

const std::string *Droid::getStatus() const
{
    return Status;
}

void Droid::setStatus(std::string *name)
{
    delete Status;
    Status = name;
}
