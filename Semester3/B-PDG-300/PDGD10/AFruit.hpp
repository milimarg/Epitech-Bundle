/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD10-florent.guittre
** File description:
** AFruit.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD10_FLORENT_GUITTRE_AFRUIT_HPP
    #define B_PDG_300_STG_3_1_PDGD10_FLORENT_GUITTRE_AFRUIT_HPP
    #include "IFruit.hpp"

class AFruit : virtual public IFruit {
public:
    AFruit();
    ~AFruit() override;
    unsigned int getVitamins() const override;
    std::string getName() const override;
    bool isPeeled() const override;
    void peel() override;
protected:
    std::string name;
    unsigned int vitamins;
    bool peelStatus = false;
};

#endif //B_PDG_300_STG_3_1_PDGD10_FLORENT_GUITTRE_AFRUIT_HPP
