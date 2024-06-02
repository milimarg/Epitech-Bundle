/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD09-florent.guittre
** File description:
** Paladin.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_PALADIN_HPP
    #define B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_PALADIN_HPP
    #include "Knight.hpp"
    #include "Priest.hpp"

class Paladin : virtual public Knight, virtual public Priest {
public:
    Paladin(const std::string &name, int power);
    ~Paladin() override;
    int attack() override;
    int special() override;
    void rest() override;
};

#endif //B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_PALADIN_HPP
