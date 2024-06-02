/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** Mutex
*/

#include "Mutex.hpp"

namespace plazza
{
    void Mutex::lock()
    {
        _mutex.lock();
    }

    void Mutex::unlock()
    {
        _mutex.unlock();
    }

    bool Mutex::trylock()
    {
        return _mutex.try_lock();
    }

    std::mutex &Mutex::get()
    {
        return _mutex;
    }
}
