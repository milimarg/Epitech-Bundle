/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07pm-florent.guittre
** File description:
** Phaser.hpp
*/

#ifndef PARADIGMSPOOL__PHASER_HPP
    #define PARADIGMSPOOL__PHASER_HPP
    #include "Sounds.hpp"

class Phaser {
public:
    typedef enum {
        REGULAR,
        PLASMA,
        ROCKET
    } AmmoType;
    Phaser(int maxAmmo, AmmoType type);
    Phaser(AmmoType type);
    Phaser();
    ~Phaser();
    void fire();
    void ejectClip();
    void changeType(AmmoType newType);
    void reload();
    void addAmmo(AmmoType type);
    int getCurrentAmmos();
private:
    static const int Empty = 0;
    int maxAmount = 20;
    int current;
    int magazine;
    AmmoType ammoType = REGULAR;
    Sounds sounds;
};

#endif //PARADIGMSPOOL__PHASER_HPP
