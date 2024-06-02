/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** Mutex
*/

#ifndef MUTEX_HPP_
    #define MUTEX_HPP_
    #include "IMutex.hpp"

namespace plazza
{
    class Mutex : public IMutex {
        public:
            Mutex() = default;
            ~Mutex() override = default;

            void lock() override;
            void unlock() override;
            bool trylock() override;
            std::mutex &get() override;

        private:
            std::mutex _mutex;
    };
}

#endif /* !MUTEX_HPP_ */
