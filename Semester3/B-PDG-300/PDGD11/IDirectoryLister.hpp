/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD11-florent.guittre
** File description:
** IDirectoryLister.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD11_FLORENT_GUITTRE_IDIRECTORYLISTER_HPP
    #define B_PDG_300_STG_3_1_PDGD11_FLORENT_GUITTRE_IDIRECTORYLISTER_HPP
    #include <iostream>
    #include <stdexcept>
    #include <cerrno>
    #include <cstring>

class IDirectoryLister {
public:
    class OpenFailureException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class NoMoreFileException : public std::exception {
    public:
        const char *what() const noexcept override;
    };
    virtual ~IDirectoryLister() = default;
    virtual bool open(const std::string &path, bool hidden) = 0;
    virtual std::string get() const = 0;
};

#endif //B_PDG_300_STG_3_1_PDGD11_FLORENT_GUITTRE_IDIRECTORYLISTER_HPP
