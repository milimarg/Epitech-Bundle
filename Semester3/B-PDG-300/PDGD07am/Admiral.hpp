/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07am-florent.guittre
** File description:
** Admiral.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_ADMIRAL_HPP
    #define B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_ADMIRAL_HPP
    #include <iostream>
    #include <functional>
    #include "Borg.hpp"
    #include "Destination.hpp"

namespace Federation {
    namespace Starfleet {
        class Admiral {
        public:
            Admiral(std::string name);
            void (Federation::Starfleet::Ship:: *firePtr)(Borg::Ship *target);
            bool (Federation::Starfleet::Ship:: *movePtr)(Destination d);
            void fire(Federation::Starfleet::Ship *ship, Borg::Ship *target);
            bool move(Federation::Starfleet::Ship *ship, Destination dest);
        private:
            std::string _name;
        };
    };
};

#endif //B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_ADMIRAL_HPP
