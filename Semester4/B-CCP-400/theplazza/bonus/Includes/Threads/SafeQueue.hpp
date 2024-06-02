/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** SafeQueue
*/

#ifndef SAFEQUEUE_HPP_
    #define SAFEQUEUE_HPP_
    #include <queue>
    #include "ScopedLock.hpp"
    #include "ConditionalVariable.hpp"

namespace plazza
{
    template<typename T>
    class SafeQueue {
        public:
            SafeQueue() = default;
            ~SafeQueue() = default;

            void push(const T& value);
            T pop();
            bool tryPop(T& value);
            bool empty() const;

        private:
            std::queue<T> _queue;
            mutable Mutex _mutex;
            ConditionalVariable _condition;
    };

    template<typename T>
    void SafeQueue<T>::push(const T& value)
    {
        {
            ScopedLock lock(_mutex);
            _queue.push(value);
        }
        _condition.notifyOne();
    }

    template<typename T>
    T SafeQueue<T>::pop()
    {
        T value;
        {
            ScopedLock lock(_mutex);
            while (_queue.empty())
                _condition.wait(_mutex);
            value = _queue.front();
            _queue.pop();
        }
        return value;
    }

    template<typename T>
    bool SafeQueue<T>::tryPop(T& value)
    {
        {
            ScopedLock lock(_mutex);
            if (_queue.empty())
                return false;
            value = _queue.front();
            _queue.pop();
        }
        return true;
    }

    template<typename T>
    bool SafeQueue<T>::empty() const
    {
        bool res = false;
        {
            ScopedLock lock(_mutex);
            res = _queue.empty();
        }
        return res;
    }
}

#endif /* !SAFEQUEUE_HPP_ */
