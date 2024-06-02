/*
** EPITECH PROJECT, 2024
** preparing-plazza
** File description:
** main
*/

#include <memory>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "SceneManager.hpp"
#include "Reception.hpp"

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
        std::string input;

        RaylibWrapper::getInstance().init(1920, 1080, "Plazza");
        plazza::SceneManager::getInstance().pushScene(std::make_unique<plazza::Reception>(multiplier, cooksPerKitchen, ingredientReplacementTime));

        plazza::SceneManager &s = plazza::SceneManager::getInstance();

        while (!RaylibWrapper::getInstance().shouldClose()) {
            s.handleEvents();
            s.update();
            s.render();
            // if (_breakLoop)
            //     break;
        }
        CloseWindow();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "An error happened" << std::endl;
    }

    return 0;
}
