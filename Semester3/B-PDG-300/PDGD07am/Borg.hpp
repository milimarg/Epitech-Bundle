/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07am-florent.guittre
** File description:
** Borg.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_BORG_HPP
    #define B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_BORG_HPP
    #include "WarpSystem.hpp"
    #include "Federation.hpp"

namespace Federation {
    namespace Starfleet {
        class Ship;
    }
    class Ship;
}

namespace Borg {
    class Ship {
    public:
        Ship(int weaponFrequency = 20, short repair = 3);
        ~Ship();
        void setupCore(WarpSystem::Core *core);
        void checkCore();
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
        int getShield();
        void setShield(int shield);
        int getTorpedo();
        void setTorpedo(int torpedo);
        int getWeaponFrequency();
        void setWeaponFrequency(int frequency);
        short getRepair();
        void setRepair(int repair);
        void fire(Federation::Starfleet::Ship *target);
        void fire(Federation::Ship *target);
        void repair();
    private:
        int _side = 300;
        short _maxWarp = 9;
        WarpSystem::Core *_core;
        Destination _home = UNICOMPLEX;
        Destination _location = _home;
        int _shield = 100;
        int _weaponFrequency;
        short _repair;
    };
};

#endif //B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_BORG_HPP
