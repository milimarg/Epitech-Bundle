/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD06-florent.guittre
** File description:
** Seminar.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD06_FLORENT_GUITTRE_SEMINAR_HPP
    #define B_PDG_300_STG_3_1_PDGD06_FLORENT_GUITTRE_SEMINAR_HPP
    #include <vector>
    #include "../seminar/Student.hpp"
    #include "../seminar/Assistant.hpp"
    #include "../seminar/Dean.hpp"

class Seminar {
public:
    Seminar();
    void run();
    void addDean(Dean *dean);
    void addAssistant(Assistant *assistant);
    void addStudent(Student *student);
private:
    std::vector<Student *> students;
    std::vector<Assistant *> assistants;
    std::vector<Dean *> deans;
};

#endif //B_PDG_300_STG_3_1_PDGD06_FLORENT_GUITTRE_SEMINAR_HPP
