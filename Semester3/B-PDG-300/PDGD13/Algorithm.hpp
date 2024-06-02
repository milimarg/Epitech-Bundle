/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD13-florent.guittre
** File description:
** Algorithm.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD13_FLORENT_GUITTRE_ALGORITHM_HPP
    #define B_PDG_300_STG_3_1_PDGD13_FLORENT_GUITTRE_ALGORITHM_HPP
#include <iostream>

template <typename T>
void swap(T &x, T &y) {
    std::swap(x, y);
}

template <typename T>
T min(T x, T y) {
    return x < y ? x : y;
}

template <typename T>
T max(T x, T y) {
    return x < y ? y : x;
}

template <typename T>
T clamp(T value, T x, T y) {
    if (value < x) {
        return x;
    }
    if (y < value) {
        return y;
    }
    return value;
}

#endif //B_PDG_300_STG_3_1_PDGD13_FLORENT_GUITTRE_ALGORITHM_HPP
