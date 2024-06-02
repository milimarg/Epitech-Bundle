/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD07pm-florent.guittre
** File description:
** Phaser.cpp
*/

#include "Phaser.hpp"

Phaser::Phaser(int maxAmmo, Phaser::AmmoType type)
{
    this->magazine = maxAmmo;
    this->ammoType = type;
    this->maxAmount = this->magazine;
    this->current = this->magazine;
    this->sounds.Regular = "Bang!";
    this->sounds.Plasma = "Bim!";
    this->sounds.Rocket = "Booooooom";
}

Phaser::Phaser(Phaser::AmmoType type)
{
    this->ammoType = type;
    this->maxAmount = this->magazine;
    this->current = this->magazine;
    this->sounds.Regular = "Bang!";
    this->sounds.Plasma = "Bim!";
    this->sounds.Rocket = "Booooooom";
}

Phaser::Phaser()
{
    this->maxAmount = this->magazine;
    this->current = this->magazine;
    this->sounds.Regular = "Bang!";
    this->sounds.Plasma = "Bim!";
    this->sounds.Rocket = "Booooooom";
}

Phaser::~Phaser() {}

void Phaser::fire()
{
    std::string noise;
    if (this->Empty) {
        std::cout << "Clip empty, please reload" << std::endl;
    } else {
        if (this->ammoType == REGULAR) {
            noise = this->sounds.Regular;
        }
        if (this->ammoType == PLASMA) {
            noise = this->sounds.Plasma;
        }
        if (this->ammoType == ROCKET) {
            noise = this->sounds.Rocket;
        }
        std::cout << noise << std::endl;
        this->current--;
    }
}

void Phaser::ejectClip()
{
    //magazine?
    this->maxAmount = 0;
}

void Phaser::changeType(Phaser::AmmoType newType)
{
    const std::string names[] = {"regular", "plasma", "rocket"};
    this->ammoType = newType;
    std::cout << "Switching ammo to type :" << names[this->ammoType] << std::endl;
}

void Phaser::reload()
{
    std::cout << "Reloading..." << std::endl;
    this->current = this->magazine;
}

void Phaser::addAmmo(Phaser::AmmoType type)
{
    if (this->ammoType != type) {
        return;
    }
    if (this->current == this->maxAmount) {
        std::cout << "Clip full" << std::endl;
        return;
    }
    this->current = this->maxAmount;
}

int Phaser::getCurrentAmmos()
{
    return (this->current);
}
