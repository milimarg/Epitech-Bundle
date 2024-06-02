/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD06-florent.guittre
** File description:
** Dean.hpp
*/
#ifndef B_PDG_300_STG_3_1_PDGD06_FLORENT_GUITTRE_DEAN_HPP
    #define B_PDG_300_STG_3_1_PDGD06_FLORENT_GUITTRE_DEAN_HPP
    #include <iostream>
    #include "Student.hpp"

class Dean {
public:
    Dean(std::string name);
    ~Dean();
    void speak(std::string action);
    void teachStudent(Student *student, std::string name);
    void timeCheck();
    bool isWorking();
    std::string getName();
private:
    const std::string _name;
    bool working = false;
};

#endif //B_PDG_300_STG_3_1_PDGD06_FLORENT_GUITTRE_DEAN_HPP
