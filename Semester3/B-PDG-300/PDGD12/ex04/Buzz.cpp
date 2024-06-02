/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD12-florent.guittre
** File description:
** Buzz.cpp
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &file)
{
    _type = Toy::ToyType::BUZZ;
    _name = name;
    setAscii(file == "" ? "buzz.txt" : file);
}

Buzz::~Buzz() {}

void Buzz::speak(const std::string &message)
{
    std::cout << "BUZZ: " << _name << " \"" << message << "\"" << std::endl;
}
