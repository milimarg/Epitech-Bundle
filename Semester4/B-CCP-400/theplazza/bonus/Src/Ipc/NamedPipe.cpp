/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** NamedPipe.cpp
*/

#include "../../Includes/Ipc/NamedPipe.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <sstream>
#include <fcntl.h>
#include <unistd.h>

namespace plazza
{
    NamedPipe::NamedPipe(const std::string &filepath)
        : _filepath(filepath), _readFd(-1), _writeFd(-1)
    {
        if (mkfifo(_filepath.c_str(), 0700) == -1)
            std::cerr << "Couldn't init mkfifo" << std::endl;
    }

    bool NamedPipe::openRead()
    {
        _readFd = open(_filepath.c_str(), O_RDONLY | O_NONBLOCK);
        if (_readFd == -1) {
            std::cerr << "Couldn't open Named Pipe (" << _filepath << ")" << std::endl;
            return false;
        }
        return true;
    }

    bool NamedPipe::openWrite()
    {
        _writeFd = open(_filepath.c_str(), O_WRONLY);
        if (_writeFd == -1) {
            std::cerr << "Couldn't open Named Pipe (" << _filepath << ")" << std::endl;
            return false;
        }
        return true;
    }

    NamedPipe::~NamedPipe()
    {
        if (_readFd != -1)
            close(_readFd);
        if (_writeFd != -1)
            close(_writeFd);
    }

    NamedPipe &NamedPipe::operator<<(const std::string &string)
    {
        if (_writeFd != -1)
            ssize_t bytes = write(_writeFd, string.c_str(), string.size());
        return *this;
    }

    NamedPipe &NamedPipe::operator<<(const char *string)
    {
        if (_writeFd != -1)
            ssize_t bytes = write(_writeFd, string, std::string(string).size());
        return *this;
    }

    NamedPipe &NamedPipe::operator>>(std::vector<std::string> &data)
    {
        data.clear();
        char buffer[1024];
        ssize_t bytesRead;
        std::string accumulatedData;

        while ((bytesRead = read(_readFd, buffer, sizeof(buffer) - 1)) > 0) {
            buffer[bytesRead] = '\0';
            accumulatedData.append(buffer);
        }

        if (bytesRead == -1 && errno != EAGAIN)
            std::cerr << "Error while reading" << std::endl;

        std::istringstream iss(accumulatedData);
        std::string line;
        while (std::getline(iss, line)) {
            std::istringstream lineStream(line);
            std::string token;
            while (std::getline(lineStream, token, ';')) {
                if (!token.empty()) {
                    data.push_back(token);
                }
            }
        }

        return *this;
    }
}
