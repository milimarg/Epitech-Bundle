/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD12-florent.guittre
** File description:
** Toy.cpp
*/

#include "Toy.hpp"

Toy::Toy() {}

Toy::Toy(Toy::ToyType type, const std::string &name, const std::string &file)
    : _type(type), _name(name)
{
    setAscii(file);
}

Toy::Toy(const Toy &toy)
{
    _type = toy._type;
    _name = toy._name;
    _picture = toy._picture;
}

Toy::~Toy() {}

Toy::ToyType Toy::getType() const
{
    return _type;
}

std::string Toy::getName() const
{
    return _name;
}

std::string Toy::getAscii() const
{
    return _picture;
}

void Toy::setName(const std::string &name)
{
    _name = name;
}

bool Toy::setAscii(const std::string &file)
{
    std::ifstream filestream;
    std::stringstream ss;

    filestream.open(file);
    if (!filestream.is_open()) {
        _picture = "ERROR";
        return false;
    }
    ss << filestream.rdbuf();
    _picture = ss.rdbuf()->str();
    return true;
}

Toy &Toy::operator=(const Toy &toy)
{
    _type = toy._type;
    _name = toy._name;
    _picture = toy._picture;
    return *this;
}
