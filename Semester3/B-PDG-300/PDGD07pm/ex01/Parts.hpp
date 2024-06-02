/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07pm-florent.guittre
** File description:
** Parts.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD07PM_FLORENT_GUITTRE_PARTS_HPP
    #define B_PDG_300_STG_3_1_PDGD07PM_FLORENT_GUITTRE_PARTS_HPP
    #include <iostream>

class Arms {
public:
    Arms(std::string serial = std::string("A-01"), bool functional = true);
    void informations() const;
    bool isFunctional() const;
    std::string &serial();
private:
    std::string _serial;
    int _functional;
};

class Legs {
public:
    Legs(std::string serial = std::string("L-01"), bool functional = true);
    void informations() const;
    bool isFunctional() const;
    std::string &serial();
private:
    std::string _serial;
    int _functional;
};

class Head {
public:
    Head(std::string serial = std::string("H-01"), bool functional = true);
    void informations() const;
    bool isFunctional() const;
    std::string &serial();
private:
    std::string _serial;
    int _functional;
};

#endif //B_PDG_300_STG_3_1_PDGD07PM_FLORENT_GUITTRE_PARTS_HPP
