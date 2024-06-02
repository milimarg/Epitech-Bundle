/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** ScopedLock
*/

#include "ScopedLock.hpp"

namespace plazza
{
    ScopedLock::ScopedLock(IMutex &mutex)
        : _mutex(mutex)
    {
        _mutex.lock();
    }

    ScopedLock::~ScopedLock()
    {
        _mutex.unlock();
    }
}
