/*
** EPITECH PROJECT, 2024
** preparing-plazza
** File description:
** main
*/

#include <memory>
#include <iostream>
#include <sstream>
#include "Reception.hpp"
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
    std::srand(std::time(NULL));

    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <multiplier> <cooks_per_kitchen> <ingredient_replacement_time_ms>" << std::endl;
        return 84;
    }

    double multiplier;
    int cooksPerKitchen;
    int ingredientReplacementTime;

    try {
        multiplier = std::stod(argv[1]);
        cooksPerKitchen = std::stoi(argv[2]);
        ingredientReplacementTime = std::stoi(argv[3]);
        if (multiplier <= 0.0 || cooksPerKitchen <= 0 || ingredientReplacementTime <= 0)
            throw plazza::Error("Bad parameters\n");
    } catch (const std::exception &e) {
        std::cerr << "Error parsing command-line arguments: " << e.what() << std::endl;
        return 84;
    }

    try {
        plazza::Reception::getInstance(multiplier, cooksPerKitchen, ingredientReplacementTime).start();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "An error happened" << std::endl;
    }

    return 0;
}
