/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** map.c
*/

#include "./include/my.h"
#include "./include/my_macros.h"

int get_map_rows(char *buffer, int filesize)
{
    int rows_nb = 0;

    for (int i = 0; i < filesize; i++) {
        if (buffer[i] == '\n')
            rows_nb++;
    }
    return (rows_nb);
}

int get_map_columns(char *buffer)
{
    int columns_nb = 0;

    for (int i = 0; buffer[i] != '\n'; i++)
        columns_nb++;
    return (columns_nb);
}

int get_boxes_nb(char *buffer, int map_size)
{
    int x_nb = 0;

    for (int i = 0; i < map_size - 1; i++)
        if (buffer[i] == BOX)
            x_nb++;
    return (x_nb);
}

int get_box_containers_nb(char *buffer, int map_size)
{
    int o_nb = 0;

    for (int i = 0; i < map_size; i++)
        if (buffer[i] == BOX_CONTAINER)
            o_nb++;
    return (o_nb);
}

int get_player_position(char *buffer, int map_size)
{
    for (int i = 0; i < map_size; i++)
        if (buffer[i] == PLAYER)
            return (i);
    return (-84);
}
