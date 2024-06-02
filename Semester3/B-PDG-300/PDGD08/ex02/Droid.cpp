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
    BattleData = new DroidMemory;
    std::cout << "Droid '" << _serial << "' Activated" << std::endl;
}

Droid::Droid(const Droid &droid)
    : _serial(droid._serial), Energy(50), Attack(25), Toughness(15),
    Status(new std::string(*droid.Status))
{
    BattleData = new DroidMemory;
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

DroidMemory *Droid::getBattleData() const
{
    return BattleData;
}

void Droid::setBattleData(DroidMemory *battleData)
{
    BattleData = battleData;
}

bool Droid::operator()(const std::string *task, size_t experience)
{
    std::string newName;
    if (Energy <= 10) {
        Energy = 0;
        setStatus(new std::string("Battery Low"));
        return false;
    }
    Energy -= 10;
    if (getBattleData()->getExp() >= experience) {
        getBattleData()->setExp(getBattleData()->getExp() + (experience / 2.0f));
        newName = *task + " - Completed!";
        setStatus(new std::string(newName));
        return true;
    } else {
        getBattleData()->setExp(getBattleData()->getExp() + experience);
        newName = *task + " - Failed!";
        setStatus(new std::string(newName));
        return false;
    }
}
