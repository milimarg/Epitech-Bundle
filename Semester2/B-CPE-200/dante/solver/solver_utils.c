/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-dante-noam.nedjar
** File description:
** solver_utils.c
*/

#include <stdlib.h>
#include "../include/structs.h"
#include "../include/solver.h"
#include "../include/common.h"

int replace_abandoned_cells(maze *my_maze)
{
    for (int y = 0; y < my_maze->height; y++) {
        for (int x = 0; x < my_maze->width; x++) {
            my_maze->map[y][x] = (my_maze->map[y][x] == ABANDONED_CELL)
            ? FREE_TO_GO_CELL : my_maze->map[y][x];
        }
    }
    return (0);
}

void run_end_of_maze(maze *my_maze, int x, int y)
{
    if (x == my_maze->width - 1 && y == my_maze->height - 1) {
        replace_abandoned_cells(my_maze);
        display_maze(my_maze);
        destroy_my_str_to_word_array(my_maze->map);
        exit(0);
    }
}
