/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD12-florent.guittre
** File description:
** Woody.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD12_FLORENT_GUITTRE_WOODY_HPP
    #define B_PDG_300_STG_3_1_PDGD12_FLORENT_GUITTRE_WOODY_HPP
    #include "Toy.hpp"

class Woody : public Toy {
public:
    Woody(const std::string &name, const std::string &file = "");
    ~Woody();
    void speak(const std::string &message) override;
    bool speak_es(const std::string &message) override;
};

#endif //B_PDG_300_STG_3_1_PDGD12_FLORENT_GUITTRE_WOODY_HPP
