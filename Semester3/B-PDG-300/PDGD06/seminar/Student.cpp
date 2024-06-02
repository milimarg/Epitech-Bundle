/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD06-florent.guittre
** File description:
** Student.cpp
*/

#include <iostream>
#include "Student.hpp"

Student::Student(std::string name)
    : _name(name)
{
    displayAction("I'm ready to learn C++.");
}

Student::~Student()
{
    displayAction("Wow, much learning today, very smart, such C++.");
}

void Student::displayAction(std::string action)
{
    std::cout << "Student " << _name << ": " << action << std::endl;
}

const std::string &Student::getName()
{
    return _name;
}

bool Student::learn(std::string text)
{
    static const std::string before = "C++";
    static const std::string after = "shit";
    int is_enough = _energy_points - 42 >= 0;
    size_t index = text.find(before, 0);

    if (is_enough) {
        _energy_points -= 42;
    } else {
        while (index != std::string::npos) {
            text.replace(index, before.length(), after);
            index = text.find(before, index + after.length());
        }
    }
    displayAction(text);
    return is_enough;
}

void Student::drink(std::string name)
{
    int autoHealth = 0;

    if (name == "Red Bull") {
        autoHealth = _energy_points + 32;
        displayAction("Red Bull gives you wings!");
    } else if (name == "Monster") {
        autoHealth = _energy_points + 64;
        displayAction("Unleash The Beast!");
    } else {
        autoHealth = _energy_points + 1;
        displayAction("ah, yes... enslaved moisture.");
    }
    _energy_points = autoHealth <= 100 ? autoHealth : 100;
}
