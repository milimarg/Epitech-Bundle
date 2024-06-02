/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07pm-florent.guittre
** File description:
** KoalaBot.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD07PM_FLORENT_GUITTRE_KOALABOT_HPP
    #define B_PDG_300_STG_3_1_PDGD07PM_FLORENT_GUITTRE_KOALABOT_HPP
    #include "Parts.hpp"

class KoalaBot {
public:
    KoalaBot(std::string serial = std::string("Bob-01"));
    ~KoalaBot();
    void setParts(Arms &arms);
    void setParts(Legs &legs);
    void setParts(Head &head);
    void swapParts(Arms &arms);
    void swapParts(Legs &legs);
    void swapParts(Head &head);
    void informations() const;
    bool status() const;
private:
    Arms _arms;
    Legs _legs;
    Head _head;
    const std::string _serial;
};

#endif //B_PDG_300_STG_3_1_PDGD07PM_FLORENT_GUITTRE_KOALABOT_HPP
