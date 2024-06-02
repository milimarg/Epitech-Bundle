/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** LineEditing
*/

#ifndef LINEEDITING_HPP_
    #define LINEEDITING_HPP_
    #include <termios.h>
    #include <unistd.h>
    #include <iostream>
    #include <vector>

class LineEditing {
    public:
        static void configureTerminal();
        static std::string readInput();
        static void restoreTerminal();

    protected:
    private:
        static bool _isEnable;
};

#endif /* !LINEEDITING_HPP_ */
