/*
** EPITECH PROJECT, 2024
** Epitech-Jam-Flamme
** File description:
** Game.hpp
*/

#ifndef EPITECH_JAM_FLAMME_GAMELOOP_HPP
    #define EPITECH_JAM_FLAMME_GAMELOOP_HPP
    #include <iostream>
    #include <vector>
    #include "RaylibWrapper.hpp"

namespace plazza
{
    class Game {
        public:
            static Game &getInstance();

            void loop();
            void close();
            bool isClosed() const;

        private:
            Game();
            ~Game();

            bool _closed;
    };
};

#endif //EPITECH_JAM_FLAMME_GAMELOOP_HPP
