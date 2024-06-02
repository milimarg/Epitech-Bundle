/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07pm-florent.guittre
** File description:
** Skat.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD07PM_FLORENT_GUITTRE_SKAT_HPP
    #define B_PDG_300_STG_3_1_PDGD07PM_FLORENT_GUITTRE_SKAT_HPP
    #include <iostream>

class Skat {
public:
    Skat(const std::string &name = std::string("bob"), int stimPaks = 15);
    ~Skat();

    int &stimPaks();
    const std::string &name();

    void shareStimPaks(int number, int &stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status();
private:
    const std::string _name;
    int _stimPaksNumber;
};

#endif //B_PDG_300_STG_3_1_PDGD07PM_FLORENT_GUITTRE_SKAT_HPP
