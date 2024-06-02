/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07pm-florent.guittre
** File description:
** KreogCom.hpp
*/
#ifndef B_PDG_300_STG_3_1_PDGD07PM_FLORENT_GUITTRE_KREOGCOM_HPP
    #define B_PDG_300_STG_3_1_PDGD07PM_FLORENT_GUITTRE_KREOGCOM_HPP
    #include <iostream>

class KreogCom {
public:
    KreogCom(int x, int y, int serial);
    ~KreogCom();

    void addCom(int x, int y, int serial);
    void addCom(KreogCom *com);
    void removeCom();
    KreogCom *getCom();

    void ping() const;
    void locateSquad() const;
private:
    const int _m_serial;
    int _x;
    int _y;
    KreogCom *kreogCom;
};

#endif //B_PDG_300_STG_3_1_PDGD07PM_FLORENT_GUITTRE_KREOGCOM_HPP
