/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** map_utils.c
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "./include/my.h"

int get_filesize(char *file)
{
    int size = 0;
    struct stat infos;

    if (stat(file, &infos) < 0)
        return (-84);
    size = infos.st_size;
    if (size == 0)
        return (-84);
    return (size);
}

void display_map(char **map, int map_sizes[], int highest_nb, int isfile)
{
    for (int x = (isfile); x < map_sizes[0]; x++) {
        write(1, map[x], map_sizes[1]);
        write(1, "\n", 1);
    }
}

int convert_map(char **map, int map_sizes[], int **new_map, int isfile)
{
    for (int x = isfile; x < map_sizes[0]; x++)
        for (int y = 0; y < map_sizes[1]; y++)
            new_map[x][y] = (map[x][y] == '.');
    return (0);
}

char **fill_map(int fd, int size)
{
    char *buffer = malloc(sizeof(char) * (size + 1));
    char **map;

    read(fd, buffer, size);
    map = my_str_to_word_array(buffer, '\n', size);
    close(fd);
    free(buffer);
    return (map);
}

int free_new_map(char **map, int **new_map, int map_sizes[], int isfile)
{
    for (int i = 0; i < map_sizes[0]; i++) {
        free(new_map[i]);
        free(map[i]);
    }
    free(new_map);
    free(map);
    return (0);
}
