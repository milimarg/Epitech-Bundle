/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** Thread
*/

#include "Thread.hpp"

namespace plazza
{
    Thread::Thread()
        : _status(ThreadStatus::DEAD),
        _started(false)
    {}

    Thread::~Thread()
    {
        join();
    }

    void Thread::join()
    {
        ScopedLock lock(_mutex);
        if (_status == ThreadStatus::STARTED && _started.exchange(false)) {
            if (_thread.joinable())
                _thread.join();
            _status = ThreadStatus::DEAD;
        }
    }

    bool Thread::running() const
    {
        return _status == ThreadStatus::STARTED;
    }

}
