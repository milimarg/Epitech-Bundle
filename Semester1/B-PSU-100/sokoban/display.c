/*
** EPITECH PROJECT, 2022
** B-PSU-100-STG-1-1-sokoban-florent.guittre
** File description:
** display
*/

#include <ncurses.h>
#include "./include/my_structs.h"

void display_map(map_t *map, int x, int y)
{
    if (map->height < y && map->width < x)
        printw(map->buffer);
    if (map->height >= y || map->width >= x)
        mvprintw(y / 2, ((x - 48) * (((x - 48) < 0) ? (-1) : 1)) / 2,
        "Your terminal is too small to display the map...");
}
