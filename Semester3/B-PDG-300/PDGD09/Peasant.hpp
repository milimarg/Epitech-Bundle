/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD09-florent.guittre
** File description:
** Peasant.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_PEASANT_HPP
    #define B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_PEASANT_HPP
    #include <iostream>
    #include "ICharacter.hpp"
    #include "IPotion.hpp"

class Peasant : virtual public ICharacter {
public:
    Peasant(const std::string &name, int power);
    ~Peasant() override;
    void setPower(int power);
    void setHp(int hp);
    bool useTechnique(int powerPoints, int damage, std::string name);
    const std::string &getName() const override;
    int getPower() const override;
    int getHp() const override;
    int attack() override;
    int special() override;
    void rest() override;
    void damage(int damage) override;
    void usePotion(int hpToAdd, int powerToAdd, const std::string &name);
    void drink(const HealthPotion &potion) override;
    void drink(const PowerPotion &potion) override;
    void drink(const PoisonPotion &potion) override;
    void drink(const IPotion &potion) override;
protected:
    std::string _name;
    int _power;
    int _health = 100;
};

#endif //B_PDG_300_STG_3_1_PDGD09_FLORENT_GUITTRE_PEASANT_HPP
