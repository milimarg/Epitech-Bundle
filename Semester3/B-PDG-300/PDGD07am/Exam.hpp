/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07am-florent.guittre
** File description:
** Exam.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_EXAM_HPP
    #define B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_EXAM_HPP
    #include <iostream>

class Exam {
public:
    Exam(bool a);
    ~Exam();
    void start(int input);
    bool isCheating() const;
    void (Exam::*kobayashiMaru)(int);
    static bool cheat;
};

#endif //B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_EXAM_HPP
