/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD06-florent.guittre
** File description:
** Dean.cpp
*/

#include <fstream>
#include "Dean.hpp"

Dean::Dean(std::string name)
    : _name(name)
{
    speak("I'm Dean " + _name + "! How do you do, fellow kids?");
}

Dean::~Dean()
{
    speak("Time to go home.");
}

void Dean::speak(std::string action)
{
    std::cout << "Dean " + _name + ": " + action << std::endl;
}

void Dean::teachStudent(Student *student, std::string name)
{
    std::ofstream out;
    int index = 0;

    static const std::string array[] = {
            "Cristaline", "Monster", "Evian", "Red Bull", "Sierra Springs"
    };

    if (student->learn(name)) {
        return;
    }
    speak("All work and no play makes " + student->getName() + " a dull student.");
    index = std::rand() % 5;
    out.open(student->getName() + ".drink");
    out << array[index] << std::endl;
    out.close();
}

void Dean::timeCheck()
{
    working = !working;
    if (working) {
        speak("Where is everyone?");
    } else {
        speak("Don't forget to close the windows when you leave.");
    }
}

bool Dean::isWorking()
{
    return working;
}

std::string Dean::getName()
{
    return _name;
}
