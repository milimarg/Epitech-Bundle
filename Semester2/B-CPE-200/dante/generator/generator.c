/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-dante-noam.nedjar
** File description:
** generator.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../include/structs.h"
#include "../include/generator.h"
#include "../include/common.h"

void fill_row(int y, maze *my_maze)
{
    int rand_coordinate = 0;
    int holes_nb = (y % 2 == 0) ? 1.25 : 1.5;
    int rand_width = my_maze->width / holes_nb;

    for (int i = 0; i < rand_width; i++) {
        rand_coordinate = rand() % (my_maze->width - 1);
        my_maze->map[y][rand_coordinate] = '*';
        verbose_mode(my_maze);
    }
}

void generate_imperfect_maze(maze *my_maze)
{
    for (int y = 0; y < my_maze->height; y++)
        fill_row(y, my_maze);
    my_maze->map[0][0] = '*';
    my_maze->map[my_maze->height - 1][my_maze->width - 1] = '*';
    my_maze->map[my_maze->height - 1][my_maze->width - 2] = '*';
    my_maze->map[my_maze->height - 2][my_maze->width - 1] = '*';
}

void maze_handler(int argc, char **argv, maze *my_maze)
{
    if (argc == 3) {
        generate_imperfect_maze(my_maze);
    }
    if (argc == 4 && my_strcmp(argv[3], "perfect") == 0) {
        generate_imperfect_maze(my_maze);
    }
}

static void set_struct_data(maze *my_maze, char **argv)
{
    my_maze->width = atoi(argv[1]);
    my_maze->height = atoi(argv[2]);
    my_maze->map = malloc(sizeof(char *) * (my_maze->height + 1));
    my_maze->verbose = 0;
    my_maze->refresh_delay = 10000;
}

int main(int argc, char **argv)
{
    maze my_maze = {0};

    srand(time(NULL));
    if (argc < 3 || argc > 4)
        return (display_usage(1));
    set_struct_data(&my_maze, argv);
    if (my_maze.width <= 1 || my_maze.height <= 1)
        return (84);
    fill_array(&my_maze);
    maze_handler(argc, argv, &my_maze);
    if (argc == 4 && my_strcmp(argv[3], "perfect") != 0)
        return (display_usage(1));
    if (!my_maze.verbose)
        display_maze(&my_maze);
    for (int i = 0; i < my_maze.height; i++)
        free(my_maze.map[i]);
    free(my_maze.map);
    return (0);
}
