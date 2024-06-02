/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD09-florent.guittre
** File description:
** Priest.hpp
*/
#ifndef B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_PRIEST_HPP
    #define B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_PRIEST_HPP
    #include "Enchanter.hpp"

class Priest : virtual public Enchanter {
public:
    Priest(const std::string &name, int power);
    ~Priest() override;
    void rest() override;
};

#endif //B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_PRIEST_HPP
