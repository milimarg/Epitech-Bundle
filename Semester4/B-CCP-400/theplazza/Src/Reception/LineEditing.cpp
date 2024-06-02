/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** LineEditing
*/

#include "LineEditing.hpp"

bool LineEditing::_isEnable = false;

void LineEditing::configureTerminal()
{
    struct termios term;

    if (LineEditing::_isEnable)
        return;
    tcgetattr(1, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(1, TCSAFLUSH, &term);
    LineEditing::_isEnable = true;
}

std::string LineEditing::readInput()
{
    std::string line;
    std::vector<char> buffer;
    size_t index = 0;
    char ch;
    bool stopItNow = false;

    if (!LineEditing::_isEnable) {
        std::getline(std::cin, line);
        return line;
    }

    while (!stopItNow) {
        ch = getchar();

        switch (ch) {
            case '\n':
                std::cout << std::endl;
                stopItNow = true;
                break;
            case 127:
                if (index == 0)
                    break;
                std::cout << "\b \b";
                buffer.erase(buffer.begin() + index - 1);
                for (size_t i = index - 1; i < buffer.size(); ++i)
                    std::cout << buffer[i];
                std::cout << " \b";
                for (size_t i = index - 1; i < buffer.size(); ++i)
                    std::cout << "\b";
                --index;
                break;
            case 27:
                ch = getchar();
                if (ch == '[') {
                    ch = getchar();
                    switch (ch) {
                        case 'D':
                            if (index == 0)
                                break;
                            std::cout << "\b";
                            --index;
                            break;
                        case 'C':
                            if (index >= buffer.size() - 1)
                                break;
                            std::cout << "\033[C";
                            ++index;
                            break;
                    }
                }
                break;
            default:
                buffer.insert(buffer.begin() + index, ch);
                std::cout << ch;
                for (size_t i = index + 1; i < buffer.size(); ++i)
                    std::cout << buffer[i];
                for (size_t i = index + 1; i < buffer.size(); ++i)
                    std::cout << "\b";
                ++index;
                break;
        }
    }

    for (char c : buffer)
        line += c;

    std::clog << "> \"" << line << "\"" << std::endl;

    return line;
}

void LineEditing::restoreTerminal()
{
    struct termios term;

    if (!LineEditing::_isEnable)
        return;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ECHO | ICANON;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
    LineEditing::_isEnable = false;
}
