/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD11-florent.guittre
** File description:
** DirectoryLister.cpp
*/

#include "DirectoryLister.hpp"

DirectoryLister::DirectoryLister() {}

DirectoryLister::DirectoryLister(const std::string &path, bool hidden)
{
    open(path, hidden);
}

DirectoryLister::~DirectoryLister()
{
    if (dir != nullptr) {
        closedir(dir);
        dir = nullptr;
    }
}

bool DirectoryLister::open(const std::string &path, bool hidden)
{
    if (dir != nullptr) {
        closedir(dir);
    }
    dir = opendir(path.c_str());
    _hidden = hidden;

    if (dir == nullptr) {
        perror(path.c_str());
        return false;
    }
    return true;
}

std::string DirectoryLister::get() const
{
    struct dirent *current = nullptr;

    if (dir == nullptr) {
        return "";
    }
    current = readdir(dir);
    if (current == nullptr) {
        return "";
    }
    if (!_hidden && current->d_name[0] == '.') {
        return get();
    }
    return std::string(current->d_name);
}
