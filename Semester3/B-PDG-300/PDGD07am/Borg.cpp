/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07am-florent.guittre
** File description:
** Borg.cpp
*/

#include "Borg.hpp"

namespace Borg {
    Ship::Ship(int weaponFrequency, short repair)
            : _weaponFrequency(weaponFrequency), _repair(repair)
    {
        std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl <<
                  "Your biological characteristics and technologies will be assimilated." << std::endl <<
                  "Resistance is futile." << std::endl;
    }

    Ship::~Ship()
    {}

    void Ship::setupCore(WarpSystem::Core *core)
    {
        _core = core;
    }

    void Ship::checkCore()
    {
        if (_core->checkReactor()->isStable()) {
            std::cout << "Everything is in order." << std::endl;
        } else {
            std::cout << "Critical failure imminent." << std::endl;
        }
    }

    bool Ship::move(int warp, Destination d)
    {
        int output = warp <= _maxWarp && d != _location && _core->checkReactor()->isStable();

        _location = d;
        return output;
    }

    bool Ship::move(int warp)
    {
        int output = warp <= _maxWarp && _core->checkReactor()->isStable();

        _location = _home;
        return output;
    }

    bool Ship::move(Destination d)
    {
        int output = d != _location && _core->checkReactor()->isStable();

        _location = d;
        return output;
    }

    bool Ship::move()
    {
        _location = _home;
        return _core->checkReactor()->isStable();
    }

    int Ship::getShield()
    {
        return _shield;
    }

    void Ship::setShield(int shield)
    {
        _shield = shield;
    }

    int Ship::getWeaponFrequency()
    {
        return _weaponFrequency;
    }

    void Ship::setWeaponFrequency(int frequency)
    {
        _weaponFrequency = frequency;
    }

    short Ship::getRepair()
    {
        return _repair;
    }

    void Ship::setRepair(int repair)
    {
        _repair = repair;
    }

    void Ship::fire(Federation::Starfleet::Ship *target)
    {
        target->setShield(target->getShield() - _weaponFrequency);
        std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
    }

    void Ship::fire(Federation::Ship *target)
    {
        target->getCore()->checkReactor()->setStability(false);
        std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
    }

    void Ship::repair()
    {
        if (_repair > 0) {
            _repair -= 1;
            _shield = 100;
            std::cout << "Begin shield re-initialisation... Done. "
                         "Awaiting further instructions." << std::endl;
            return;
        }
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
    }
}
