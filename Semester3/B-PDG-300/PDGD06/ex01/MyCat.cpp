/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD06-florent.guittre
** File description:
** MyCat.cpp
*/

#include <iostream>
#include <fstream>

static int readFiles(int argc, char **argv)
{
    std::ifstream file;
    int error = 0;

    for (int i = 0; i < argc; i++) {
        file.open(argv[i]);
        if (!file.is_open()) {
            std::cerr << "MyCat: " << argv[i] << ": No such file or directory" << std::endl;
            error = 84;
        }
        std::cout << file.rdbuf();
        file.close();
    }
    return error;
}

static void readStdin()
{
    std::string line;

    while (!std::cin.eof()) {
        std::getline(std::cin, line);
        std::cout << line << std::endl;
    }
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        readStdin();
        return 0;
    }
    return readFiles(argc - 1, &argv[1]);
}
