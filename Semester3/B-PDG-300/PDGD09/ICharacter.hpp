/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD09-florent.guittre
** File description:
** ICharacter.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_ICHARACTER_HPP
    #define B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_ICHARACTER_HPP
    #include <iostream>
    #include "IPotion.hpp"
    #include "HealthPotion.hpp"
    #include "PowerPotion.hpp"
    #include "PoisonPotion.hpp"

class ICharacter {
public:
    ICharacter() = default;
    virtual ~ICharacter() = default;
    virtual int attack() = 0;
    virtual int special() = 0;
    virtual void rest() = 0;
    virtual void damage(int damage) = 0;
    virtual const std::string &getName() const = 0;
    virtual int getHp() const = 0;
    virtual int getPower() const = 0;
    virtual void drink(const HealthPotion &potion) = 0;
    virtual void drink(const PowerPotion &potion) = 0;
    virtual void drink(const PoisonPotion &potion) = 0;
    virtual void drink(const IPotion &potion) = 0;
};

#endif //B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_ICHARACTER_HPP
