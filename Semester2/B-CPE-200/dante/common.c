/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-dante-noam.nedjar
** File description:
** common.c
*/

#include <unistd.h>
#include "include/structs.h"
#include "include/common.h"

void display_maze(maze *my_maze)
{
    for (int i = 0; my_maze->map[i] != NULL; i++) {
        write(1, my_maze->map[i], my_maze->width);
        if (i != my_maze->height - 1)
            write(1, "\n", 1);
    }
}

int anti_glitch(int x, int y, maze *my_maze)
{
    int is_glitching = 0;

    if (x < 0 || x >= my_maze->width)
        is_glitching = 1;
    if (y < 0 || y >= my_maze->height)
        is_glitching = 1;
    return (is_glitching);
}

void verbose_mode(maze *my_maze)
{
    if (my_maze->verbose) {
        write(1, CLEAR_SYMBOL, CLEAR_SYMBOL_LEN);
        display_maze(my_maze);
        usleep(my_maze->refresh_delay);
    }
}

int display_usage(int is_generator)
{
    if (is_generator) {
        write(2, "Usage: ./generator x y [perfect]\n", 33);
    } else {
        write(2, "Usage: ./solver x y\n", 20);
    }
    return (84);
}
