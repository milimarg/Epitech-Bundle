/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** Process
*/

#include "Process.hpp"

namespace plazza
{
    pid_t Process::forkProcess()
    {
        _pid = fork();
        if (_pid == -1)
            throw std::runtime_error("Failed to fork process");
        return _pid;
    }

    void Process::waitForChild()
    {
        int status = 0;

        if (isChild())
            throw std::logic_error("Process cannot wait for itself");
        if (waitpid(_pid, &status, 0) == -1)
            throw std::runtime_error("Failed to wait for child process");
    }

    bool Process::isChild() const
    {
        return _pid == 0;
    }

    pid_t Process::getPID() const
    {
        return _pid;
    }
}
