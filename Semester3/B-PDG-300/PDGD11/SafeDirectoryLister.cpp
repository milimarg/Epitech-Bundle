/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD11-florent.guittre
** File description:
** SafeSafeSafeDirectoryLister.cpp
*/

#include "SafeDirectoryLister.hpp"

SafeDirectoryLister::SafeDirectoryLister() {}

SafeDirectoryLister::SafeDirectoryLister(const std::string &path, bool hidden)
{
    open(path, hidden);
}

SafeDirectoryLister::~SafeDirectoryLister()
{
    if (dir != nullptr) {
        closedir(dir);
    }
}

bool SafeDirectoryLister::open(const std::string &path, bool hidden)
{
    if (dir != nullptr) {
        closedir(dir);
    }
    dir = opendir(path.c_str());
    _hidden = hidden;

    if (dir == nullptr) {
        throw IDirectoryLister::OpenFailureException();
    }
    return true;
}

std::string SafeDirectoryLister::get() const
{
    struct dirent *current = nullptr;

    if (dir == nullptr) {
        return "";
    }
    current = readdir(dir);
    if (current == nullptr) {
        throw IDirectoryLister::NoMoreFileException();
    }
    if (!_hidden && current->d_name[0] == '.') {
        return get();
    }
    return std::string(current->d_name);
}
