/*
** EPITECH PROJECT, 2022
** B-MUL-100-STG-1-1-myradar-florent.guittre
** File description:
** entity_animation
*/

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
