/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD08-florent.guittre
** File description:
** DroidMemory.cpp
*/

#include <stdlib.h>
#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
    :   Fingerprint(std::rand()) {}

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
