/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD08-florent.guittre
** File description:
** Droid.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD08_FLORENT_GUITTRE_DROID_HPP
    #define B_PDG_300_STG_3_1_PDGD08_FLORENT_GUITTRE_DROID_HPP
    #include <iostream>
    #include <stddef.h>
    #include "DroidMemory.hpp"

class Droid {
public:
    Droid(std::string serial = std::string(""), size_t Energy = 50,
          size_t Attack = 25, size_t Toughness = 15,
          std::string status = std::string("Standing by"));
    Droid(const Droid &droid);
    ~Droid();
    Droid &operator=(Droid const &droid) {
        _serial = droid._serial;
        Energy = droid.Energy;
        delete Status;
        Status = new std::string(*droid.Status);
        return *this;
    }
    bool operator!=(const Droid &droid2) const {
        return !(*this == droid2);
    }
    bool operator==(const Droid &other) const {
        return *Status == *other.Status;
    }
    Droid &operator<<(size_t &energy) {
        static const int max = 100;
        if (Energy + energy >= max) {
            energy -= (max - Energy);
            Energy = max;
        } else {
            Energy += energy;
            energy = 0;
        }
        return *this;
    }

    std::string getId() const;
    void setId(std::string serial);
    size_t getEnergy() const;
    void setEnergy(size_t energy);
    size_t getAttack() const;
    size_t getToughness() const;
    const std::string *getStatus() const;
    void setStatus(std::string *name);
    DroidMemory *getBattleData() const;
    void setBattleData(DroidMemory *battleData);
private:
    std::string _serial;
    size_t Energy;
    const size_t Attack;
    const size_t Toughness;
    std::string *Status;
    DroidMemory *BattleData;
};

static std::ostream &operator << (std::ostream &os, Droid const &droid)
{
    size_t temp = droid.getEnergy();

    temp = temp > 100 ? 100 : temp;
    return os << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << temp;
}

#endif //B_PDG_300_STG_3_1_PDGD08_FLORENT_GUITTRE_DROID_HPP
