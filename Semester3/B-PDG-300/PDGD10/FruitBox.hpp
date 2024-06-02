/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD10-florent.guittre
** File description:
** FruitBox.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD10_FLORENT_GUITTRE_FRUITBOX_HPP
    #define B_PDG_300_STG_3_1_PDGD10_FLORENT_GUITTRE_FRUITBOX_HPP
    #include "IFruit.hpp"
    #include <deque>
    #include <algorithm>

class FruitBox {
public:
    FruitBox(unsigned int size);
    ~FruitBox();
    unsigned int getSize() const;
    unsigned int nbFruits() const;
    bool pushFruit(IFruit *fruit);
    IFruit *popFruit();
    const std::deque<IFruit *> &getBox() const;
    bool isFull() const;
private:
    std::deque<IFruit *> box;
    unsigned int _size;
};

static std::ostream &operator<<(std::ostream &os, FruitBox const &fruit)
{
    unsigned int i = 0;

    os << "[";
    for (auto &elem : fruit.getBox()) {
        os << *elem << std::noboolalpha;
        if (i < fruit.nbFruits() - 1) {
            os << ", ";
        }
        i++;
    }
    return os << "]";
}

#endif //B_PDG_300_STG_3_1_PDGD10_FLORENT_GUITTRE_FRUITBOX_HPP
