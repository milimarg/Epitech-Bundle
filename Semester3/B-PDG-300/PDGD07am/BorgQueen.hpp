/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07am-florent.guittre
** File description:
** BorgQueen.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_BORGQUEEN_HPP
    #define B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_BORGQUEEN_HPP
    #include <functional>
    #include "Borg.hpp"

namespace Borg {
    class BorgQueen {
    public:
        BorgQueen();
        void (Borg::Ship:: *firePtr)(Federation::Starfleet::Ship *target);
        bool (Borg::Ship:: *movePtr)(Destination d);
        void (Borg::Ship:: *destroyPtr)(Federation::Ship *target);
        bool move(Borg::Ship *ship, Destination dest);
        void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
        void destroy(Borg::Ship *ship, Federation::Ship *target);
    };
};

#endif //B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_BORGQUEEN_HPP
