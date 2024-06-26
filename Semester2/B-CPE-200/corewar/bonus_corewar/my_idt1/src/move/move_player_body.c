/*
** EPITECH PROJECT, 2023
** doom
** File description:
** move_player_body.c
*/

#include "../../include/my.h"

void move_front(my_idt1 *world, sfVector2i *delta)
{
    world->player.x += delta->x;
    world->player.y += delta->y;
}

void move_back(my_idt1 *world, sfVector2i *delta)
{
    world->player.x -= delta->x;
    world->player.y -= delta->y;
}

void turn_left(my_idt1 *world, sfVector2i *delta)
{
    world->player.angle = fix_angle(world->player.angle - 4);
}

void turn_right(my_idt1 *world, sfVector2i *delta)
{
    world->player.angle = fix_angle(world->player.angle + 4);
}
