/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD08-florent.guittre
** File description:
** DroidMemory.cpp
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() {}

size_t DroidMemory::getFingerprint() const
{
    return Fingerprint;
}

void DroidMemory::setFingerprint(size_t fingerprint)
{
    Fingerprint = fingerprint;
}

size_t DroidMemory::getExp() const
{
    return Exp;
}

void DroidMemory::setExp(size_t exp)
{
    Exp = exp;
}

DroidMemory &DroidMemory::operator<<(DroidMemory &other) {
    Exp += other.Exp;
    Fingerprint ^= other.Fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &other) {
    other.Exp += Exp;
    Fingerprint = other.Fingerprint ^ Fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator+=(DroidMemory const &other) {
    Exp += other.Exp;
    Fingerprint ^= other.Fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator+=(const size_t number) {
    Exp += number;
    Fingerprint ^= number;
    return *this;
}

DroidMemory DroidMemory::operator+(DroidMemory const &other) {
    DroidMemory output;

    output.setExp(output.getExp() + other.getExp());
    output.setFingerprint(output.getFingerprint() ^ other.getFingerprint());
    return output;
}

DroidMemory DroidMemory::operator+(const size_t &number) {
    DroidMemory output;

    output.Exp = Exp + number;
    output.Fingerprint = Fingerprint ^ number;
    return output;
}

bool DroidMemory::operator==(DroidMemory &memory) const
{
    return Exp == memory.Exp && Fingerprint == memory.Fingerprint;
}

bool DroidMemory::operator!=(DroidMemory &memory) const
{
    return !(*this == memory);
}

bool DroidMemory::operator<(DroidMemory &memory) const
{
    return Exp < memory.Exp;
}

bool DroidMemory::operator>(DroidMemory &memory) const
{
    return Exp > memory.Exp;
}

bool DroidMemory::operator<=(DroidMemory &memory) const
{
    return Exp <= memory.Exp;
}

bool DroidMemory::operator>=(DroidMemory &memory) const
{
    return Exp >= memory.Exp;
}
