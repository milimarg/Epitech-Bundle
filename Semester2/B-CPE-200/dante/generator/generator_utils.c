/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-dante-noam.nedjar
** File description:
** generator_utils.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/structs.h"

static void set_cell_content_condition(maze *my_maze, int i, int j)
{
    if (i % 2 == 0) {
        my_maze->map[i][j] = (j % 2) ? 'X' : '*';
    } else {
        my_maze->map[i][j] = 'X';
    }
}

int fill_array(maze *my_maze)
{
    int i = 0;

    for (i = 0; i < my_maze->height; i++) {
        my_maze->map[i] = malloc(sizeof(char) * (my_maze->width + 1));
        my_maze->map[i][my_maze->width] = 0;
        for (int j = 0; j < my_maze->width; j++) {
            set_cell_content_condition(my_maze, i, j);
        }
    }
    my_maze->map[i] = NULL;
}
