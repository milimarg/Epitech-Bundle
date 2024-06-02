/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD12-florent.guittre
** File description:
** Buzz.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD12_FLORENT_GUITTRE_BUZZ_HPP
    #define B_PDG_300_STG_3_1_PDGD12_FLORENT_GUITTRE_BUZZ_HPP
    #include "Toy.hpp"

class Buzz : public Toy {
public:
    Buzz(const std::string &name, const std::string &file = "");
    ~Buzz();
    void speak(const std::string &message) override;
};

#endif //B_PDG_300_STG_3_1_PDGD12_FLORENT_GUITTRE_BUZZ_HPP
