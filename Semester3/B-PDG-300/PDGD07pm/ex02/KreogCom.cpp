/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07pm-florent.guittre
** File description:
** KreogCom.cpp
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial)
    :  _m_serial(serial), _x(x), _y(y), kreogCom(nullptr)
{
    std::cout << "KreogCom " << _m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << _m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *node = new KreogCom(x, y, serial);
    KreogCom *temp = this;

    if (kreogCom == nullptr) {
        kreogCom = node;
    } else {
        temp = kreogCom;
        node->kreogCom = temp;
        kreogCom = node;
    }
}

void KreogCom::addCom(KreogCom *com)
{
    this->addCom(com->_x, com->_y, com->_m_serial);
}

KreogCom *KreogCom::getCom()
{
    return kreogCom;
}

void KreogCom::removeCom()
{
    KreogCom *deleted = kreogCom;

    if (kreogCom == nullptr) {
        delete this;
    } else {
        kreogCom = kreogCom->kreogCom;
        delete deleted;
    }
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << _m_serial << " currently at " << _x << " " << _y << std::endl;
}

void KreogCom::locateSquad() const
{
    for (KreogCom *temp = this->kreogCom; temp != nullptr; temp = temp->kreogCom) {
        temp->ping();
    }
    this->ping();
}
