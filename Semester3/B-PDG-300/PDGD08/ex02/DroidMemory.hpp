/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD08-florent.guittre
** File description:
** DroidMemory.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD08_FLORENT_GUITTRE_DROIDMEMORY_HPP
    #define B_PDG_300_STG_3_1_PDGD08_FLORENT_GUITTRE_DROIDMEMORY_HPP
    #include <stddef.h>
    #include <iostream>

class DroidMemory {
public:
    DroidMemory();
    size_t getFingerprint() const;
    void setFingerprint(size_t fingerprint);
    size_t getExp() const;
    void setExp(size_t exp);
    DroidMemory &operator<<(DroidMemory &other);
    DroidMemory &operator>>(DroidMemory &other);
    DroidMemory &operator+=(DroidMemory const &other);
    DroidMemory &operator+=(size_t number);
    DroidMemory operator+(DroidMemory const &other);
    DroidMemory operator+(const size_t &number);
    bool operator==(DroidMemory &memory) const;
    bool operator!=(DroidMemory &memory) const;
    bool operator<(DroidMemory &memory) const;
    bool operator>(DroidMemory &memory) const;
    bool operator<=(DroidMemory &memory) const;
    bool operator>=(DroidMemory &memory) const;
private:
    size_t Fingerprint = std::rand();
    size_t Exp = 0;
};

static std::ostream &operator<<(std::ostream &os, DroidMemory const &memory)
{
    return os << "DroidMemory '" << memory.getFingerprint() << "', " << memory.getExp();
}

#endif //B_PDG_300_STG_3_1_PDGD08_FLORENT_GUITTRE_DROIDMEMORY_HPP
