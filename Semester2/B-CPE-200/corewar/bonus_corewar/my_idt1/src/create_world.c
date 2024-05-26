/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** create_world.c
*/

#include <stdlib.h>
#include <string.h>
#include "../include/my.h"

static void set_window_infos(my_idt1 *world, map_type type,
sfKeyCode reload_key)
{
    world->map.pixel_scale = 8;
    world->map.win_size = (sfVector2f){800, 600};
    world->map.opengl_size.x = world->map.win_size.x * world->map.pixel_scale;
    world->map.opengl_size.y = world->map.win_size.y * world->map.pixel_scale;
    world->map.type = type;
    world->map.reload_key = reload_key;
}

static my_idt1 *world_creator(my_idt1_player *player)
{
    my_idt1 *world = malloc(sizeof(my_idt1));

    world->pre_cos = malloc(sizeof(double) * 360);
    world->pre_sin = malloc(sizeof(double) * 360);
    for (int i = 0; i < 360; i++) {
        world->pre_cos[i] = cos(deg_to_rad(i));
        world->pre_sin[i] = sin(deg_to_rad(i));
    }
    world->player = *player;
    world->points = sfVertexArray_create();
    world->no_spam_key = 0;
    world->i = 0;
    return (world);
}

my_idt1 *create_world_from_file(char *filepath, map_type type,
sfKeyCode reload_key, my_idt1_player *player)
{
    my_idt1 *world = world_creator(player);

    world->filepath = filepath;
    set_window_infos(world, type, reload_key);
    if (world->map.type == DANTE)
        convert_dante_to_config(world->filepath);
    parse_file(world);
    return (world);
}

my_idt1 *create_world_from_memory(sfVector2u *size, my_idt1_player *player)
{
    my_idt1 *world = world_creator(player);
    int surface = size->x * size->y;

    world->size = *size;
    world->filepath = NULL;
    set_window_infos(world, -1, -1);
    allocate_sectors(world, surface);
    return (world);
}
