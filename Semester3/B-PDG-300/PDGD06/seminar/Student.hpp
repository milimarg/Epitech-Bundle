/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD06-florent.guittre
** File description:
** Student.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD06_FLORENT_GUITTRE_STUDENT_HPP
    #define B_PDG_300_STG_3_1_PDGD06_FLORENT_GUITTRE_STUDENT_HPP
    #include <iostream>

class Student {
public:
    Student(std::string name);
    ~Student();
    void displayAction(std::string action);
    const std::string &getName();
    bool learn(std::string text);
    void drink(std::string name);
private:
    const std::string _name;
    int _energy_points = 100;
};

#endif //B_PDG_300_STG_3_1_PDGD06_FLORENT_GUITTRE_STUDENT_HPP
