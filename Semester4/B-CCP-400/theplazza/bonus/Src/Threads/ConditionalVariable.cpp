/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** ConditionalVariable
*/

#include "ConditionalVariable.hpp"

namespace plazza
{
    void ConditionalVariable::wait(Mutex &mutex)
    {
        std::unique_lock<std::mutex> lock(mutex.get());

        _condition.wait(lock);
    }

    void ConditionalVariable::notifyOne()
    {
        _condition.notify_one();
    }

    void ConditionalVariable::notifyAll()
    {
        _condition.notify_all();
    }
}
