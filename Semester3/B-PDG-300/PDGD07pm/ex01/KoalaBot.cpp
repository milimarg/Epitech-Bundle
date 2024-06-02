/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07pm-florent.guittre
** File description:
** KoalaBot.cpp
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial)
    : _serial(serial) {}

KoalaBot::~KoalaBot() {}

void KoalaBot::setParts(Arms &arms)
{
    _arms = arms;
}

void KoalaBot::setParts(Legs &legs)
{
    _legs = legs;
}

void KoalaBot::setParts(Head &head)
{
    _head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    std::swap(_arms, arms);
}

void KoalaBot::swapParts(Legs &legs)
{
    std::swap(_legs, legs);
}

void KoalaBot::swapParts(Head &head)
{
    std::swap(_head, head);
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}

bool KoalaBot::status() const
{
    return _arms.isFunctional() && _legs.isFunctional() && _head.isFunctional();
}
