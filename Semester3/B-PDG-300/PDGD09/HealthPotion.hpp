/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD09-florent.guittre
** File description:
** HealthPotion.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_HEALTHPOTION_HPP
    #define B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_HEALTHPOTION_HPP
    #include "IPotion.hpp"

class HealthPotion : public IPotion {
    public:
    HealthPotion();
    ~HealthPotion() override;
    int getHealth() const override;
    int getPower() const override;
};

#endif //B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_HEALTHPOTION_HPP
