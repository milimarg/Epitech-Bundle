/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD12-florent.guittre
** File description:
** Toy.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD12_FLORENT_GUITTRE_TOY_HPP
    #define B_PDG_300_STG_3_1_PDGD12_FLORENT_GUITTRE_TOY_HPP
    #include <iostream>
    #include <fstream>
    #include <sstream>

class Toy {
public:
    enum ToyType {
        BASIC_TOY,
        ALIEN,
    };
    Toy();
    Toy(ToyType type, const std::string &name, const std::string &file);
    Toy(const Toy &toy);
    ~Toy();
    Toy::ToyType getType() const;
    std::string getName() const;
    std::string getAscii() const;
    void setName(const std::string &name);
    bool setAscii(const std::string &file);
    Toy &operator=(const Toy &toy);
private:
    Toy::ToyType _type = Toy::ToyType::BASIC_TOY;
    std::string _name = "toy";
    std::string _picture = "";
};

#endif //B_PDG_300_STG_3_1_PDGD12_FLORENT_GUITTRE_TOY_HPP
