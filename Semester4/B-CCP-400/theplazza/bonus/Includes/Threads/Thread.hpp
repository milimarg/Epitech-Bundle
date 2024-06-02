/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** Thread
*/

#ifndef THREAD_HPP_
    #define THREAD_HPP_
    #include <atomic>
    #include "ScopedLock.hpp"
    #include "Mutex.hpp"

namespace plazza
{
    class Thread {
        public:
            Thread();
            ~Thread();

            template<typename Function, typename... Args>
            void start(Function&& func, Args&&... args)
            {
                ScopedLock lock(_mutex);
                if (_status != ThreadStatus::DEAD || _started.exchange(true))
                    return;
                _thread = std::thread(std::forward<Function>(func), std::forward<Args>(args)...);
                _status = ThreadStatus::STARTED;
            }
            void join();
            bool running() const;

        private:
            enum class ThreadStatus {
                STARTED,
                RUNNING,
                DEAD
            };

            mutable Mutex _mutex;
            std::thread _thread;
            ThreadStatus _status;
            std::atomic<bool> _started;
    };
}

#endif /* !THREAD_HPP_ */
