/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** main.c
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include "../include/structs.h"
#include "../include/solver.h"
#include "../include/common.h"

static int search_path(int x, int y, maze *my_maze, int iterations)
{
    int coordinates[] = {x, y, x + 1, y, x, y + 1, x - 1, y, x, y - 1};
    int a = 0;

    for (int i = 0; i < 10; i += 2) {
        x = coordinates[i];
        y = coordinates[i + 1];
        if (!anti_glitch(x, y, my_maze) &&
            my_maze->map[y][x] == FREE_TO_GO_CELL) {
            my_maze->map[y][x] = PATH_CELL;
            verbose_mode(my_maze);
            run_end_of_maze(my_maze, x, y);
            a = search_path(x, y, my_maze, ++iterations);
            my_maze->map[y][x] = ABANDONED_CELL;
        }
    }
    return (a);
}

int init_maze(maze *my_maze, char *buffer)
{
    srand(time(NULL));
    my_maze->width = 0;
    my_maze->height = 0;
    my_maze->map = my_str_to_word_array(buffer);
    for (; my_maze->map[0][my_maze->width] != '\0'; my_maze->width++);
    for (; my_maze->map[my_maze->height] != NULL; my_maze->height++);
    my_maze->verbose = 0;
    my_maze->refresh_delay = 10000;
    return (0);
}

int main(int argc, char **argv)
{
    struct stat st = {0};
    char *buffer = NULL;
    int fd = 0;
    maze my_maze = {0};

    if (argc > 1 && !stat(argv[1], &st)) {
        if (st.st_size == 0)
            return (84);
        buffer = malloc(sizeof(char) * (st.st_size + 1));
        fd = open(argv[1], O_RDONLY);
        read(fd, buffer, st.st_size);
        close(fd);
        buffer[st.st_size] = 0;
        init_maze(&my_maze, buffer);
        search_path(0, 0, &my_maze, 0);
        write(1, "no solution found", 17);
    }
    return (0);
}
