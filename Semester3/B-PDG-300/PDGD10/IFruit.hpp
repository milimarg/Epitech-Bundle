/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD10-florent.guittre
** File description:
** IFruit.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD10_FLORENT_GUITTRE_IFRUIT_HPP
    #define B_PDG_300_STG_3_1_PDGD10_FLORENT_GUITTRE_IFRUIT_HPP
    #include <iostream>

class IFruit {
public:
    IFruit();
    virtual ~IFruit() = default;
    virtual unsigned int getVitamins() const = 0;
    virtual std::string getName() const = 0;
    virtual bool isPeeled() const = 0;
    virtual void peel() = 0;
    bool operator==(IFruit &fruit);
};

static std::ostream &operator<<(std::ostream &os, IFruit const &fruit)
{
    return os << std::boolalpha << "[name: \"" << fruit.getName() <<
       "\", vitamins: " << fruit.getVitamins() << ", peeled: " << fruit.isPeeled() << "]";
}

#endif //B_PDG_300_STG_3_1_PDGD10_FLORENT_GUITTRE_IFRUIT_HPP
