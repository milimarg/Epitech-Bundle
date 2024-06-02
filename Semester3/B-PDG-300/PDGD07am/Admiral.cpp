/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07am-florent.guittre
** File description:
** Admiral.cpp
*/

#include "Admiral.hpp"

namespace Federation {
    namespace Starfleet {
        Admiral::Admiral(std::string name)
            : _name(name)
        {
            std::cout << "Admiral " << _name << " ready for action." << std::endl;
            firePtr = &Ship::fire;
            movePtr = &Ship::move;
        }

        void
        Admiral::fire(Federation::Starfleet::Ship *ship, Borg::Ship *target)
        {
            std::cout << "On order from Admiral " << _name << ":" << std::endl;
            (ship->*firePtr)(target);
        }

        bool
        Admiral::move(Federation::Starfleet::Ship *ship, Destination dest)
        {
            return (ship->*movePtr)(dest);
        }
    }
}
