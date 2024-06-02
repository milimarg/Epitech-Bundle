/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD11-florent.guittre
** File description:
** IDirectoryLister.cpp
*/

#include "IDirectoryLister.hpp"

const char *IDirectoryLister::OpenFailureException::what() const noexcept
{
    return strerror(errno);
}

const char *IDirectoryLister::NoMoreFileException::what() const noexcept
{
    return "End of stream";
}
