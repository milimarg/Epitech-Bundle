/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD12-florent.guittre
** File description:
** Picture.cpp
*/

#include "Picture.hpp"

Picture::Picture() {}

Picture::Picture(const Picture &picture)
{
    getPictureFromFile(picture._file);
}

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

Picture::~Picture() {}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream filestream;
    std::stringstream ss;

    _file = file;
    filestream.open(file);
    if (!filestream.is_open()) {
        _data = "ERROR";
        return false;
    }
    ss << filestream.rdbuf();
    _data = ss.rdbuf()->str();
    return true;
}

Picture &Picture::operator=(const Picture &picture)
{
    _data = picture._data;
    _file = picture._file;
    return *this;
}
