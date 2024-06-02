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
    void operator=(const Droid &droid) {
        _serial = droid._serial;
        Energy = droid.Energy;
        delete Status;
        Status = new std::string(*droid.Status);
    }
    bool operator!=(const Droid &droid2) const {
        return !(*this == droid2);
    }
    bool operator==(const Droid &other) const {
        return *Status == *other.Status;
    }
    void operator<<(size_t &energy) {
        size_t toLoad = energy > 100 ? 100 : energy;
        setEnergy(getEnergy() + toLoad);

        if (energy < toLoad) {
            energy = 0;
        } else {
            energy -= toLoad;
        }
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
    bool operator()(const std::string *task, size_t experience);
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
    return os << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
}

#endif //B_PDG_300_STG_3_1_PDGD08_FLORENT_GUITTRE_DROID_HPP
