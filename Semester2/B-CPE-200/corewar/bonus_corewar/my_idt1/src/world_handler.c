/*
** EPITECH PROJECT, 2023
** doom
** File description:
** world_handler.c
*/

#include <stdlib.h>
#include "../include/my.h"

void destroy_world(my_idt1 *world)
{
    for (int i = 0; i < world->sectors_nb; i++) {
        free(world->sectors[i]->walls);
        free(world->sectors[i]->points_surface);
        free(world->sectors[i]);
    }
    free(world->sectors);
    free(world->pre_cos);
    free(world->pre_sin);
    free(world);
}

void display_world(my_idt1 *world)
{
    sfVector3i *wpos = malloc(sizeof(sfVector3i) * 4);

    sort_sectors(world);
    for (int s = 0; s < world->sectors_nb; s++) {
        world->sectors[s]->d = 0;
        set_surface_type(world, s);
        if (world->sectors[s]->walls_nb == 0)
            continue;
        for (int loop = 0; loop < 2; loop++) {
            draw_one_wall(world, loop, s, wpos);
            world->sectors[s]->d /= world->sectors[s]->walls_nb;
            world->sectors[s]->surface *= -1;
        }
    }
    free(wpos);
}
