/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-dante-noam.nedjar
** File description:
** common.h
*/
#ifndef COMMON_H_
    #define COMMON_H_
    #define CLEAR_SYMBOL "\e[1;1H\e[2J"
    #define CLEAR_SYMBOL_LEN 10
    #define WALL_CELL 'X'
    #define PATH_CELL 'o'
    #define FREE_TO_GO_CELL '*'
    #define ABANDONED_CELL '@'
void display_maze(maze *my_maze);
int anti_glitch(int x, int y, maze *my_maze);
void verbose_mode(maze *my_maze);
int display_usage(int is_generator);
#endif /*COMMON_H_*/
