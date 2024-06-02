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
    DroidMemory &operator<<(DroidMemory &other) {
        Exp += other.Exp;
        Fingerprint ^= other.Fingerprint;
        return *this;
    }
    DroidMemory &operator>>(DroidMemory &other) {
        other.Exp += Exp;
        Fingerprint = other.Fingerprint ^ Fingerprint;
        return *this;
    }
    DroidMemory &operator+=(DroidMemory const &other) {
        Exp += other.Exp;
        Fingerprint ^= other.Fingerprint;
        return *this;
    }
    DroidMemory &operator+=(const size_t number) {
        Exp += number;
        Fingerprint ^= number;
        return *this;
    }
    DroidMemory operator+(const size_t &number) const {
        DroidMemory output;

        output.Exp = Exp + number;
        output.Fingerprint = Fingerprint ^ number;
        return output;
    }
    DroidMemory operator+(const DroidMemory &other) const {
        DroidMemory output;

        output.Exp += other.Exp;
        output.Fingerprint ^= other.Fingerprint;
        return output;
    }
private:
    size_t Fingerprint;
    size_t Exp = 0;
};

static std::ostream &operator << (std::ostream &os, DroidMemory const &memory)
{
    return os << "DroidMemory '" << memory.getFingerprint() << "', " << memory.getExp();
}

#endif //B_PDG_300_STG_3_1_PDGD08_FLORENT_GUITTRE_DROIDMEMORY_HPP
