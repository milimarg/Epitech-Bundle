/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07pm-florent.guittre
** File description:
** Skat.cpp
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks)
    : _name(name), _stimPaksNumber(stimPaks) {}

Skat::~Skat() {}

int &Skat::stimPaks()
{
    return _stimPaksNumber;
}

const std::string &Skat::name()
{
    return _name;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number > _stimPaksNumber) {
        std::cout << "Don't be greedy" << std::endl;
        return;
    }
    stock += number;
    _stimPaksNumber -= number;
    std::cout << "Keep the change." << std::endl;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
    }
    _stimPaksNumber += number;
}

void Skat::useStimPaks()
{
    if (_stimPaksNumber > 0) {
        _stimPaksNumber -= 1;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    } else {
        std::cout << "Mediiiiiic" << std::endl;
    }
}

void Skat::status()
{
    std::cout << "Soldier " << _name << " reporting " <<
    _stimPaksNumber << " stimpaks remaining sir!" << std::endl;
}
