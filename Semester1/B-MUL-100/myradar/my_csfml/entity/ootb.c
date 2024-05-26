/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** ootb
*/

#include <SFML/Graphics.h>
#include "../animation/animation.h"
#include "../window/window.h"
#include "entity.h"

int ootb_x(int left_or_right, my_entity *entity, my_window *window)
{
    int o = 0;
    int sprite_size = entity->animation->size.x /
    entity->animation->sprite_nb;

    if (!left_or_right)
        o = sprite_size * (-1);
    else
        o = window->width + sprite_size;
    return (o);
}

int ootb_y(int up_or_down, my_entity *entity, my_window *window)
{
    int o = 0;
    int sprite_size = entity->animation->size.y;

    if (!up_or_down)
        o = sprite_size * (-1);
    else
        o = window->height + sprite_size;
    return (o);
}
