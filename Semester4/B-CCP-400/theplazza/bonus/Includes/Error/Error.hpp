/*
** EPITECH PROJECT, 2024
** preparing-plazza
** File description:
** Error
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_

#include <exception>
#include <string>

namespace plazza
{
    class Error : public std::exception {
        public:
            Error(std::string what) : _what(what) {}

            const char *what() const throw() override;

        private:
            std::string _what;
    };
};

#endif /* !ERROR_HPP_ */
