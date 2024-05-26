/*
** EPITECH PROJECT, 2023
** doom
** File description:
** move_player_view.c
*/

#include "../../include/my.h"

void go_up(my_idt1 *world, sfVector2i *delta)
{
    world->player.z++;
}

void go_down(my_idt1 *world, sfVector2i *delta)
{
    world->player.z--;
}

void lean_to_ground(my_idt1 *world, sfVector2i *delta)
{
    world->player.look++;
    if (world->player.look < -10)
        world->player.look = -10;
    if (world->player.look > 10)
        world->player.look = 10;
}

void lean_to_sky(my_idt1 *world, sfVector2i *delta)
{
    world->player.look--;
    if (world->player.look < -10)
        world->player.look = -10;
    if (world->player.look > 10)
        world->player.look = 10;
}

void clip_behind_player(sfVector3i *one, sfVector3i *two)
{
    float delta_a = one->y;
    float delta_b = two->y;
    float s = delta_a / (delta_a - delta_b);

    one->x = one->x + s * (two->x - one->x);
    one->y = one->y + s * (two->y - one->y);
    one->y = (one->y == 0) ? 1 : one->y;
    one->z = one->z + s * (two->z - one->z);
}
