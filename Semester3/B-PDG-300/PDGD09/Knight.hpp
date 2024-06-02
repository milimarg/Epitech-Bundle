/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD09-florent.guittre
** File description:
** Knight.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_KNIGHT_HPP
    #define B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_KNIGHT_HPP
    #include "Peasant.hpp"

class Knight : virtual public Peasant {
public:
    Knight(const std::string &name, int power);
    ~Knight() override;
    int attack() override;
    int special() override;
    void rest() override;
};

#endif //B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_KNIGHT_HPP
