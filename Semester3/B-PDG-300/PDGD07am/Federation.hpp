/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07am-florent.guittre
** File description:
** Federation.hpp
*/
#ifndef B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_FEDERATION_HPP
    #define B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_FEDERATION_HPP
    #include <iostream>
    #include "WarpSystem.hpp"

namespace Borg {
    class Ship;
}

    #include "Borg.hpp"

namespace Federation {
    namespace Starfleet {
        class Captain {
        public:
            Captain(std::string name);
            ~Captain();
            std::string getName();
            int getAge();
            void setAge(int age);
        private:
            std::string _name;
            int _age;
        };
        class Ship {
        public:
            Ship(int length = 289, int width = 132, std::string name = "Entreprise", short maxWarp = 6,
                 int torpedo = 0);
            ~Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            void promote(Captain *captain);
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int getShield();
            void setShield(int shield);
            int getTorpedo();
            void setTorpedo(int torpedo);
            void fire(Borg::Ship *target);
            void fire(int torpedoes, Borg::Ship *target);
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Captain *_captain;
            Destination _home = VULCAN;
            Destination _location = _home;
            int _shield = 100;
            int _photonTorpedo;
        };
        class Ensign {
        public:
            Ensign(std::string name);
            ~Ensign();
        private:
            std::string _name;
        };
    }
    class Ship {
    public:
        Ship(int length, int width, std::string name);
        ~Ship();
        void setupCore(WarpSystem::Core *core);
        void checkCore();
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
        WarpSystem::Core *getCore();
    private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp = 1;
        WarpSystem::Core *_core;
        Destination _home = EARTH;
        Destination _location = _home;
    };
}

#endif //B_PDG_300_STG_3_1_PDGD07AM_FLORENT_GUITTRE_FEDERATION_HPP
