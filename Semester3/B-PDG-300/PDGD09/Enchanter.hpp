/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD09-florent.guittre
** File description:
** Enchanter.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_ENCHANTER_HPP
    #define B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_ENCHANTER_HPP
    #include "Peasant.hpp"

class Enchanter : virtual public Peasant {
public:
    Enchanter(const std::string &name, int power);
    ~Enchanter();
    int attack() override;
    int special() override;
    void rest() override;
};

#endif //B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_ENCHANTER_HPP
