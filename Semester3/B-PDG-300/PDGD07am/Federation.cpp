/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07am-florent.guittre
** File description:
** Federation.cpp
*/

#include "Federation.hpp"

namespace Federation {
    namespace Starfleet {
        Ship::Ship(int length, int width, std::string name, short maxWarp,
                   int torpedo)
                : _length(length), _width(width), _name(name), _maxWarp(maxWarp),
                  _photonTorpedo(torpedo)
        {
            std::cout << "The ship USS " << _name << " has been finished." << std::endl <<
                      "It is " << _length << " m in length and " << _width << " m in width." << std::endl <<
                      "It can go to Warp " << _maxWarp << "!" << std::endl;
            if (_photonTorpedo > 0) {
                std::cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
            }
        }

        Ship::~Ship() {}

        void Ship::setupCore(WarpSystem::Core *core)
        {
            _core = core;
            std::cout << "USS " << _name << ": The core is set." << std::endl;
        }

        void Ship::checkCore()
        {
            std::string stable = _core->checkReactor()->isStable() ? "stable" : "unstable";

            std::cout << "USS " << _name << ": The core is " << stable << " at the time." << std::endl;
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

        int Ship::getTorpedo()
        {
            return _photonTorpedo;
        }

        void Ship::setTorpedo(int torpedo)
        {
            _photonTorpedo = torpedo;
        }

        void Ship::fire(Borg::Ship *target)
        {
            Federation::Starfleet::Ship::fire(1, target);
        }

        void Ship::fire(int torpedoes, Borg::Ship *target)
        {
            if (_photonTorpedo <= 0) {
                std::cout << _name << ": No more torpedo to fire, " <<
                          _captain->getName() << "!" << std::endl;
                return;
            }
            if (torpedoes > _photonTorpedo) {
                std::cout << _name << ": No enough torpedoes to fire, " <<
                          _captain->getName() << "!" << std::endl;
                return;
            }
            _photonTorpedo -= torpedoes;
            target->setShield(target->getShield() - 50 * torpedoes);

            std::cout << _name << ": Firing on target. " <<
                      _photonTorpedo << " torpedoes remaining." << std::endl;
        }

        Captain::Captain(std::string name)
                : _name(name) {}
        ///////

        Captain::~Captain() {}

        std::string Captain::getName()
        {
            return _name;
        }

        int Captain::getAge()
        {
            return _age;
        }

        void Captain::setAge(int age)
        {
            _age = age;
        }

        void Ship::promote(Federation::Starfleet::Captain *captain)
        {
            _captain = captain;
            std::cout << _captain->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
        }

        Ensign::Ensign(std::string name)
        {
            _name = name;
            std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
        }

        Ensign::~Ensign() {}
    }
    Ship::Ship(int length, int width, std::string name)
            : _length(length), _width(width), _name(name)
    {
        if (_maxWarp > 1) {
            _maxWarp = 1;
        }
        std::cout << "The independent ship " << _name << " just finished its construction." << std::endl <<
                  "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    }

    Ship::~Ship() {}

    void Ship::setupCore(WarpSystem::Core *core)
    {
        _core = core;
        std::cout << _name << ": The core is set." << std::endl;
    }

    void Ship::checkCore()
    {
        std::string stable = _core->checkReactor()->isStable() ? "stable" : "unstable";

        std::cout << _name << ": The core is " << stable << " at the time." << std::endl;
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

    WarpSystem::Core *Ship::getCore()
    {
        return _core;
    }
};
