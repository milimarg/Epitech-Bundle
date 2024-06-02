/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD12-florent.guittre
** File description:
** Picture.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD12_FLORENT_GUITTRE_PICTURE_HPP
    #define B_PDG_300_STG_3_1_PDGD12_FLORENT_GUITTRE_PICTURE_HPP
    #include <iostream>
    #include <fstream>
    #include <sstream>

class Picture {
public:
    Picture();
    Picture(const std::string &file);
    ~Picture();
    bool getPictureFromFile(const std::string &file);
    std::string _data = "";
private:
    std::string _file;
};

#endif //B_PDG_300_STG_3_1_PDGD12_FLORENT_GUITTRE_PICTURE_HPP
