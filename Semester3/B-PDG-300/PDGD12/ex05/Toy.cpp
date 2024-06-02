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

Toy::~Toy()
{
    delete lastError;
}

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
        throw Toy::Error("setAscii");
        return false;
    }
    ss << filestream.rdbuf();
    _picture = ss.rdbuf()->str();
    return true;
}

void Toy::speak(const std::string &message)
{
    std::cout << _name << " \"" << message << "\"" << std::endl;
}

bool Toy::speak_es(const std::string &message)
{
    throw Toy::Error("speak_es");
    return false;
}

Toy::Error Toy::getLastError()
{
    return *lastError;
}

Toy &Toy::operator=(const Toy &toy)
{
    _type = toy._type;
    _name = toy._name;
    _picture = toy._picture;
    return *this;
}

Toy &Toy::operator<<(const std::string &message)
{
    std::cout << _name << std::endl << message << std::endl;
    return *this;
}

void Toy::setLastError(const std::string &location, Toy::Error::ErrorType type)
{
    lastError->_location = location;
    lastError->type = type;
}

Toy::Error::Error() {}

Toy::Error::Error(const std::string &location)
        : _location(location)
{
    if (_location == "setAscii") {
        type = Toy::Error::PICTURE;
    }
    if (_location == "speak_es") {
        type = Toy::Error::SPEAK;
    }
    this->setLastError(location, type);
}

const char *Toy::Error::what() const noexcept
{
    if (type == PICTURE) {
        return "bad new illustration";
    }
    if (type == SPEAK) {
        return "wrong mode";
    }
    return "";
}

std::string Toy::Error::where() const
{
    return _location;
}
