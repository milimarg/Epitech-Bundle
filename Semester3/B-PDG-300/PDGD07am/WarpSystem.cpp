/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07am-florent.guittre
** File description:
** WarpSystem.cpp
*/

#include "WarpSystem.hpp"

namespace WarpSystem {
    QuantumReactor::QuantumReactor() {}

    QuantumReactor::~QuantumReactor() {}

    bool QuantumReactor::isStable()
    {
        return _stability;
    }

    void QuantumReactor::setStability(bool stability)
    {
        _stability = stability;
    }

    Core::Core(WarpSystem::QuantumReactor *coreReactor)
    {
        _coreReactor = coreReactor;
    }

    Core::~Core() {}

    QuantumReactor *WarpSystem::Core::checkReactor()
    {
        return _coreReactor;
    }
}
