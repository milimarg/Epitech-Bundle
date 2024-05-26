/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** main.c
*/

#include "./include/my.h"
#include "./include/my_macros.h"

int main(int argc, char **argv)
{
    int a = sokoban_handler(argc, argv);
    endwin();
    return (a);
}
