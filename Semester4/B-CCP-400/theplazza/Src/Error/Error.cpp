/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-florent.guittre
** File description:
** Error
*/

#include "Error.hpp"

namespace plazza
{
    const char *Error::what() const throw()
    {
        static std::string errorMessage = this->_what;
        return errorMessage.c_str();
    }
}
