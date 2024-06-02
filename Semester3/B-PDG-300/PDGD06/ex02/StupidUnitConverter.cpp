/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD06-florent.guittre
** File description:
** StupidUnitConverter.cpp
*/

#include <iostream>
#include <sstream>
#include <cstring>

int main(void)
{
    float value;
    std::string unit;
    std::string line;
    std::stringstream stream;

    while (!std::cin.eof()) {
        std::cout.precision(3);
        std::cout.width(16);
        std::getline(std::cin, line);
        stream << line;
        stream >> value >> unit;

        if (unit == "Celsius") {
            std::cout << std::fixed << (value * 9.0f / 5.0f) + 32;
            std::cout.width(16);
            std::cout << "Fahrenheit" << std::endl;
        }
        if (unit == "Fahrenheit") {
            std::cout << std::fixed << (5.0 / 9.0) * (value - 32);
            std::cout.width(16);
            std::cout << "Celsius" << std::endl;
        }
        unit = "";
    }
    return 0;
}
