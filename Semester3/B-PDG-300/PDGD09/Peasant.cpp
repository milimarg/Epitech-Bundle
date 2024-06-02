/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD09-florent.guittre
** File description:
** Peasant.cpp
*/

#include "Peasant.hpp"

Peasant::Peasant(const std::string &name, int power)
    : _name(name), _power(power)
{
    std::cout << _name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << _name << " is back to his crops." << std::endl;
}

const std::string &Peasant::getName() const
{
    return _name;
}

int Peasant::getPower() const
{
    return _power;
}

void Peasant::setPower(int power)
{
    _power = power;
    _power = _power < 0 ? 0 : _power;
    _power = _power > 100 ? 100 : _power;
}

int Peasant::getHp() const
{
    return _health;
}

void Peasant::setHp(int hp)
{
    _health = hp;
    _health = _health < 0 ? 0 : _health;
    _health = _health > 100 ? 100 : _health;
}

bool Peasant::useTechnique(int powerPoints, int damage, std::string name)
{
    if (_health <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        setHp(0);
        return false;
    }
    if (_power - powerPoints < 0) {
        std::cout << _name << " is out of power." << std::endl;
        return false;
    }
    setPower(getPower() - powerPoints);
    setHp(getHp() - damage);
    std::cout << name << std::endl;
    return true;
}

int Peasant::attack()
{
    static const int cost = 10;
    static const int damage = 5;

    if (!useTechnique(cost, 0, _name + " tosses a stone.")) {
        return 0;
    }
    return damage;
}

int Peasant::special()
{
    static const int cost = 0;
    static const int damage = 0;

    if (!useTechnique(cost, 0, _name + " doesn't know any special move.")) {
        return 0;
    }
    return damage;
}

void Peasant::rest()
{
    static const int cost = 0;
    static const int damage = 0;

    useTechnique(cost, damage, _name + " takes a nap.");
    if (_health == 0) {
        return;
    }
    setPower(getPower() + 30);
}

void Peasant::damage(int damage)
{
    setHp(getHp() - damage);
    if (_health == 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    std::cout << _name << " takes " << std::to_string(damage) << " damage." << std::endl;
}

void Peasant::usePotion(int hpToAdd, int powerToAdd, const std::string &name)
{
    setHp(getHp() + hpToAdd);
    setPower(getPower() + powerToAdd);
    std::cout << name << std::endl;
}

void Peasant::drink(const HealthPotion &potion)
{
    usePotion(potion.getHealth(), potion.getPower(), _name + " feels rejuvenated.");
}

void Peasant::drink(const PowerPotion &potion)
{
    usePotion(potion.getHealth(), potion.getPower(), _name + "'s power is restored.");
}

void Peasant::drink(const PoisonPotion &potion)
{
    usePotion(potion.getHealth(), potion.getPower(), _name + " has been poisoned.");
}

void Peasant::drink(const IPotion &potion)
{
    usePotion(potion.getHealth(), potion.getPower(), _name + " drinks a mysterious potion.");
}
