/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD11-florent.guittre
** File description:
** SafeDirectoryLister.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD11_FLORENT_GUITTRE_SAFEDIRECTORYLISTER_HPP
    #define B_PDG_300_STG_3_1_PDGD11_FLORENT_GUITTRE_SAFEDIRECTORYLISTER_HPP
    #include "IDirectoryLister.hpp"
    #include <dirent.h>
    #include <stdio.h>

class SafeDirectoryLister : public IDirectoryLister {
public:
    SafeDirectoryLister();
    SafeDirectoryLister(const std::string &name, bool hidden);
    ~SafeDirectoryLister() override;
    bool open(const std::string &path, bool hidden) override;
    std::string get() const override;
private:
    DIR *dir = nullptr;
    bool _hidden;
};

#endif //B_PDG_300_STG_3_1_PDGD11_FLORENT_GUITTRE_SAFEDIRECTORYLISTER_HPP
