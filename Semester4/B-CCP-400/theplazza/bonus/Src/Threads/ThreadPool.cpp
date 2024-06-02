/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** ThreadPool
*/

#include "ThreadPool.hpp"

namespace plazza
{
    ThreadPool::ThreadPool(size_t numThreads)
        : _numThreads(numThreads), _stop(false)
    {}

    ThreadPool::~ThreadPool()
    {
        {
            ScopedLock lock(_mutex);
            _stop = true;
        }
        _condition.notifyAll();
        for (auto &thread : _threads)
            thread->join();
    }

    void ThreadPool::start()
    {
        for (size_t i = 0; i < _numThreads; ++i) {
            _threads.push_back(std::make_unique<Thread>());
            _threads.back()->start([this] { this->workerThread(); });
        }
    }

    void ThreadPool::workerThread()
    {
        bool isEmpty = false;
        while (true) {
            std::function<void()> task;
            isEmpty = _tasks.empty();
            _condition.wait(_mutex, [this] { return _stop || !_tasks.empty(); });
            if (_stop && _tasks.empty())
                return;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            task = _tasks.pop();
            task();
        }
    }
}
