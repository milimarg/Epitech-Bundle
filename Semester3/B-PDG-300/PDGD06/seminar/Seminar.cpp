/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD06-florent.guittre
** File description:
** Seminar.cpp
*/

#include <algorithm>
#include "Seminar.hpp"

Seminar::Seminar()
{}

static void displayAssistants(std::vector<Assistant *> &assistants)
{
    std::cout << "Teaching assistants: ";
    for (auto it = assistants.begin(); it != assistants.end(); it++) {
        std::cout << std::to_string((*it)->getId());
        if (it != std::prev(assistants.end())) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

static void displayStudents(std::vector<Student *> &students)
{
    std::cout << "Students: ";
    for (auto it = students.begin(); it != students.end(); it++) {
        std::cout << (*it)->getName();
        if (it != std::prev(students.end())) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

void Seminar::run()
{
    bool toggle = 0;
    std::string drinkName;

    if (students.size() == 0 ||
        assistants.size() == 0 ||
        deans.size() == 0) {
        std::cout << "Seminar: "
                     "A C++ seminar needs at least one Dean of Studies, "
                     "one Assistant and one Student." << std::endl;
        return;
    }
    std::cout << "Seminar: Begining 6th day of seminar." << std::endl;
    std::cout << "Dean of Studies: " << deans[0]->getName() << std::endl;
    displayAssistants(assistants);
    displayStudents(students);
    deans[0]->timeCheck();
    for (auto &assistant : assistants) {
        assistant->timeCheck();
    }
    for (int i = 0; i < 2; i++) {
        for (auto &student : students) {
            student->learn("I'm learning C++!");
            assistants[toggle]->helpStudent(student);
            toggle = !toggle;
        }
    }
    for (auto &student : students) {
        deans[0]->teachStudent(student, "I'm learning C++!");
        drinkName = assistants[toggle]->readDrink(student->getName());
        assistants[toggle]->giveDrink(student, drinkName);
        toggle = !toggle;
    }
    for (auto &student : students) {
        deans[0]->teachStudent(student, "I'm learning C++!");
        assistants[toggle]->helpStudent(student);
        toggle = !toggle;
    }
    for (auto &student : students) {
        deans[0]->teachStudent(student, "I'm learning C++!");
        assistants[toggle]->helpStudent(student);
        toggle = !toggle;
    }
    deans[0]->timeCheck();
    for (auto &assistant : assistants) {
        assistant->timeCheck();
    }
}

void Seminar::addDean(Dean *dean)
{
    if (deans.size() == 0) {
        deans.push_back(dean);
        std::cout << "Seminar: Dean " << dean->getName() << " is here." << std::endl;
    } else {
        std::cout << "Seminar: There can only be one Dean of Studies." << std::endl;
    }
}

void Seminar::addAssistant(Assistant *assistant)
{
    auto assistantComp = [assistant](Assistant *a) {
        return a->getId() == assistant->getId();
    };

    if (std::find_if(assistants.begin(), assistants.end(), assistantComp) != assistants.end()) {
        std::cout << "Seminar: Assistant " << std::to_string(assistant->getId()) <<
        " is already registered." << std::endl;
        return;
    }
    if (assistants.size() < 2) {
        assistants.push_back(assistant);
        std::cout << "Seminar: Assistant " << std::to_string(assistant->getId()) <<
        " joined the pedagogical team." << std::endl;
    } else {
        std::cout << "Seminar: There is only room for two Teaching Assistants." << std::endl;
    }
}

void Seminar::addStudent(Student *student)
{
    auto studentComp = [student](Student *a) {
        return a->getName() == student->getName();
    };

    if (std::find_if(students.begin(), students.end(), studentComp) != students.end()) {
        std::cout << "Seminar: Student " << student->getName() <<
                  " is already registered." << std::endl;
        return;
    }
    if (students.size() < 5) {
        students.push_back(student);
        std::cout << "Seminar: Student " << student->getName() << " joined the seminar." << std::endl;
    } else {
        std::cout << "Seminar: There is only room for five Students." << std::endl;
    }
}
