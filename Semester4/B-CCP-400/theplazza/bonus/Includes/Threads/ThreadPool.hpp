/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** ThreadPool
*/

#ifndef THREAD_POOL_HPP_
    #define THREAD_POOL_HPP_
    #include <iostream>
    #include <vector>
    #include <array>
    #include <functional>
    #include "SafeQueue.hpp"
    #include "Thread.hpp"

namespace plazza
{
    class ThreadPool {
        public:
            ThreadPool(size_t numThreads);
            ~ThreadPool();

            void start();

            template<typename Function, typename... Args>
            void addTask(Function&& func, Args&&... args);

        private:
            void workerThread();

            size_t _numThreads;
            std::vector<std::unique_ptr<Thread>> _threads;
            SafeQueue<std::function<void()>> _tasks;
            Mutex _mutex;
            ConditionalVariable _condition;
            bool _stop;
    };

    template<typename Function, typename... Args>
    void ThreadPool::addTask(Function &&func, Args &&...args)
    {
        _tasks.push(std::bind(std::forward<Function>(func), std::forward<Args>(args)...));
        _condition.notifyOne();
    }
}

#endif /* THREAD_POOL_HPP_ */
