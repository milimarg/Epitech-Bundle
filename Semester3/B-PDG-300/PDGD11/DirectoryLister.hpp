/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD11-florent.guittre
** File description:
** DirectoryLister.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD11_FLORENT_GUITTRE_DIRECTORYCLASSER_HPP
    #define B_PDG_300_STG_3_1_PDGD11_FLORENT_GUITTRE_DIRECTORYCLASSER_HPP
    #include "IDirectoryLister.hpp"
    #include <dirent.h>
    #include <stdio.h>

class DirectoryLister : public IDirectoryLister {
public:
    DirectoryLister();
    DirectoryLister(const std::string &name, bool hidden);
    ~DirectoryLister() override;
    bool open(const std::string &path, bool hidden) override;
    std::string get() const override;
private:
    DIR *dir = nullptr;
    bool _hidden;
};

#endif //B_PDG_300_STG_3_1_PDGD11_FLORENT_GUITTRE_DIRECTORYCLASSER_HPP
