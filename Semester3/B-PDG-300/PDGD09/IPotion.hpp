/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD09-florent.guittre
** File description:
** IPotion.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_IPOTION_HPP
    #define B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_IPOTION_HPP

class IPotion {
public:
    IPotion() = default;
    virtual ~IPotion() = default;
    virtual int getHealth() const = 0;
    virtual int getPower() const = 0;
protected:
    int healthToAdd;
    int powerToAdd;
};

#endif //B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_IPOTION_HPP
