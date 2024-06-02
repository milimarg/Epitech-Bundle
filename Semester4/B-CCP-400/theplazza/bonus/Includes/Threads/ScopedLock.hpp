/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** ScopedLock
*/

#ifndef SCOPEDLOCK_HPP_
    #define SCOPEDLOCK_HPP_
    #include "IMutex.hpp"

namespace plazza
{
    class ScopedLock {
        public:
            explicit ScopedLock(IMutex &mutex);
            ~ScopedLock();

        private:
            IMutex &_mutex;
    };
}

#endif /* !SCOPEDLOCK_HPP_ */
