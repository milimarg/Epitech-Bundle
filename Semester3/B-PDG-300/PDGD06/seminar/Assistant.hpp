/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD06-florent.guittre
** File description:
** Assistant.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD06_FLORENT_GUITTRE_ASSISTANT_HPP
    #define B_PDG_300_STG_3_1_PDGD06_FLORENT_GUITTRE_ASSISTANT_HPP
    #include <iostream>
    #include "Student.hpp"

class Assistant {
public:
    Assistant(int number);
    ~Assistant();
    void speak(std::string text);
    int getId();
    bool isWorking();
    void giveDrink(Student *student, std::string name);
    std::string readDrink(std::string studentName);
    void helpStudent(Student *student);
    void timeCheck();
private:
    const int _id;
    bool working = false;
};

#endif //B_PDG_300_STG_3_1_PDGD06_FLORENT_GUITTRE_ASSISTANT_HPP
