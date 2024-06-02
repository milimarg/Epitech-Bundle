/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07am-florent.guittre
** File description:
** WarpSystem.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_WARPSYSTEM_HPP
    #define B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_WARPSYSTEM_HPP
    #include <iostream>
    #include "Destination.hpp"

namespace WarpSystem {
    class QuantumReactor {
    public:
        QuantumReactor();
        ~QuantumReactor();
        bool isStable();
        void setStability(bool stability);
    private:
        bool _stability = true;
    };

    class Core {
    public:
        ~Core();
        Core(QuantumReactor *coreReactor);
        QuantumReactor *checkReactor();
    private:
        QuantumReactor *_coreReactor;
    };
};

#endif //B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_WARPSYSTEM_HPP
