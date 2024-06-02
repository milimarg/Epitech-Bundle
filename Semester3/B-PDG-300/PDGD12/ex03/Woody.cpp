/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD12-florent.guittre
** File description:
** Woody.cpp
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &file)
{
    _type = Toy::ToyType::WOODY;
    _name = name;
    setAscii(file == "" ? "woody.txt" : file);
}

Woody::~Woody() {}

void Woody::speak(const std::string &message)
{
    std::cout << "WOODY: " << _name << " \"" << message << "\"" << std::endl;
}
