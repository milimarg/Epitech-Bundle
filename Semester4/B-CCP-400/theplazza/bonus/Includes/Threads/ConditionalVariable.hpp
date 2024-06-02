/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** ConditionalVariable
*/

#ifndef CONDITIONAL_VARIABLE_HPP_
    #define CONDITIONAL_VARIABLE_HPP_
    #include "Mutex.hpp"
    #include <condition_variable>

namespace plazza
{
    class ConditionalVariable {
        public:
            ConditionalVariable() = default;
            ~ConditionalVariable() = default;

            template <typename Predicate>
            void wait(Mutex &mutex, Predicate pred);

            void wait(Mutex &mutex);
            void notifyOne();
            void notifyAll();

        private:
            std::condition_variable _condition;
    };

    template <typename Predicate>
    void ConditionalVariable::wait(Mutex &mutex, Predicate pred)
    {
        std::unique_lock<std::mutex> lock(mutex.get());
        _condition.wait(lock, pred);
    }
}

#endif /* CONDITIONAL_VARIABLE_HPP_ */
