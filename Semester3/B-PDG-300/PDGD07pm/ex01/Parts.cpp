/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07pm-florent.guittre
** File description:
** Parts.cpp
*/

#include "Parts.hpp"

Arms::Arms(std::string serial, bool functional)
    : _serial(serial), _functional(functional)
{}

Legs::Legs(std::string serial, bool functional)
    : _serial(serial), _functional(functional)
{}

Head::Head(std::string serial, bool functional)
    : _serial(serial), _functional(functional)
{}

bool Arms::isFunctional() const
{
    return _functional;
}

bool Legs::isFunctional() const
{
    return _functional;
}

bool Head::isFunctional() const
{
    return _functional;
}

std::string &Arms::serial()
{
    return _serial;
}

std::string &Legs::serial()
{
    return _serial;
}

std::string &Head::serial()
{
    return _serial;
}

void Arms::informations() const
{
    std::string status = _functional ? "OK" : "KO";

    std::cout << "\t[Parts] Arms " << _serial << " status : " << status << std::endl;
}

void Legs::informations() const
{
    std::string status = _functional ? "OK" : "KO";

    std::cout << "\t[Parts] Legs " << _serial << " status : " << status << std::endl;
}

void Head::informations() const
{
    std::string status = _functional ? "OK" : "KO";

    std::cout << "\t[Parts] Head " << _serial << " status : " << status << std::endl;
}
