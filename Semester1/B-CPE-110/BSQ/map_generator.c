/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** map_pattern.c
*/

#include <stdlib.h>
#include "./include/my.h"

int check_map_pattern(char **argv)
{
    if (argv[2][0] == '\0')
        return (84);
    return (0);
}

char **map_generator(int argc, char **argv, int square_size)
{
    char **map;
    char *square_pattern = "";
    int square_pattern_len = 0;
    int shift = 0;

    square_pattern = argv[2];
    square_pattern_len = my_strlen(square_pattern);
    map = malloc(sizeof(char *) * (square_size + 1));
    for (int x = 0; x < square_size; x++)
        map[x] = malloc(sizeof(char) * (square_size + 1));
    for (int x = 0; x < square_size; x++) {
        for (int y = 0; y < square_size; y++) {
            map[x][y] = square_pattern[shift];
            shift++;
            shift = (shift >= square_pattern_len) ? 0 : shift;
        }
    }
    return (map);
}
