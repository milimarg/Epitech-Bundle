/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07am-florent.guittre
** File description:
** Exam.cpp
*/

#include "Exam.hpp"

bool Exam::cheat = false;

Exam::Exam(bool a)
{
    Exam::cheat = false;
}

Exam::~Exam() {}

void Exam::start(int input)
{
    std::cout << "[The exam is starting]" << std::endl;
    std::cout << input << " Klingon vessels appeared out of nowhere." << std::endl;
    std::cout << "they are fully armed and shielded" << std::endl;
    if (!cheat) {
        std::cout << "This exam is hard... you lost again." << std::endl;
    } else {
        std::cout << "What the... someone changed the parameters of the exam !" << std::endl;
    }
}

bool Exam::isCheating() const
{
    return cheat;
}
