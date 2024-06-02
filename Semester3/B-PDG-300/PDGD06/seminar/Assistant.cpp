/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD06-florent.guittre
** File description:
** Assistant.cpp
*/

#include <fstream>
#include <stdio.h>
#include "Assistant.hpp"

Assistant::Assistant(int id)
    : _id(id)
{
    speak("'morning everyone");
}

Assistant::~Assistant()
{
    speak("see you tomorrow at 9.00");
}

void Assistant::speak(std::string text)
{
    std::cout << "Assistant " << _id << ": " << text << " *sip coffee*" << std::endl;
}

int Assistant::getId()
{
    return _id;
}

bool Assistant::isWorking()
{
    return working;
}

void Assistant::giveDrink(Student *student, std::string name)
{
    speak("drink this, " + student->getName());
    student->drink(name);
}

std::string Assistant::readDrink(std::string studentName)
{
    std::ifstream file;
    std::string drinkName;
    std::string filename = studentName + ".drink";

    file.open(filename);
    if (file.is_open()) {
        std::getline(file, drinkName);
        speak(studentName + " needs a " + drinkName);
        file.close();
        remove(filename.c_str());
        return drinkName;
    }
    return std::string("");
}

void Assistant::helpStudent(Student *student)
{
    std::string drinkName;

    drinkName = readDrink(student->getName());
    if (drinkName == "") {
        speak(student->getName() + " seems fine");
        return;
    }
    giveDrink(student, drinkName);
}

void Assistant::timeCheck()
{
    working = !working;
    if (working) {
        speak("Time to teach some serious business");
    } else {
        speak("Enough teaching for today");
    }
}
