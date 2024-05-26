/*
** EPITECH PROJECT, 2022
** B-MUL-100-STG-1-1-myradar-florent.guittre
** File description:
** entity_animation
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "../window/window.h"
#include "../animation/animation.h"
#include "entity.h"

int add_moves(my_entity *entity)
{
    sfIntRect rectangle = {0};

    for (int i = 0; i < entity->animation->sprite_nb; i++) {
        rectangle.width =
        entity->animation->size.x / entity->animation->sprite_nb;
        rectangle.height = entity->animation->size.y;
        rectangle.left = rectangle.width * i;
        rectangle.top = 0;
        entity->animation->textures[i] =
        sfTexture_createFromFile(entity->animation->path, &rectangle);
    }
    return (0);
}

void update_animation(my_entity *entity)
{
    sfSprite_setTexture(entity->animation->sprite,
    entity->animation->textures[entity->animation->i], sfTrue);
    entity->animation->i = (entity->animation->i ==
    entity->animation->sprite_nb - 1) ? 0 : entity->animation->i + 1;
    return;
}

void display_entity(my_window *window, my_entity *entity)
{
    sfRenderWindow_drawSprite(window->renderer, entity->animation->sprite,
    NULL);
}
