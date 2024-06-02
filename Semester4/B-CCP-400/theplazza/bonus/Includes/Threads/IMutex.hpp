/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** IMutex
*/

#ifndef IMUTEX_HPP_
    #define IMUTEX_HPP_
    #include <iostream>
    #include <thread>
    #include <vector>
    #include <mutex>

namespace plazza
{
    class IMutex {
        public:
            virtual ~IMutex() = default;
            virtual void lock() = 0;
            virtual void unlock() = 0;
            virtual bool trylock() = 0;
            virtual std::mutex &get() = 0;
    };
}

#endif /* !IMUTEX_HPP_ */
