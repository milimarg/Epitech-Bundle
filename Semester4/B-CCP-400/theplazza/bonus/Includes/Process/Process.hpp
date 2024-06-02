/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** Process
*/

#ifndef PROCESS_HPP_
    #define PROCESS_HPP_

    #include <unistd.h>
    #include <stdexcept>
    #include <iostream>
    #include <vector>
    #include <string>
    #include <sys/wait.h>

namespace plazza
{
    class Process {
        public:
            Process() = default;
            ~Process() = default;

            pid_t forkProcess();
            void waitForChild();
            bool isChild() const;
            pid_t getPID() const;

        private:
            pid_t _pid = -1;
    };
}

#endif // PROCESS_HPP_
