/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** entity
*/

#include <stdlib.h>
#include "entity.h"
#include "../lib/lib.h"

int set_spawnpoint(my_entity *entity, float x, float y, float angle)
{
    float last_angle = sfSprite_getRotation(entity->animation->sprite);

    entity->position.x = x;
    entity->position.y = y;
    sfSprite_setPosition(entity->animation->sprite, entity->position);
    sfSprite_rotate(entity->animation->sprite, (last_angle * (-1)));
    sfSprite_rotate(entity->animation->sprite, angle);
    return (0);
}

int move_entity(my_entity *entity, float x, float y, float angle)
{
    entity->position.x = x;
    entity->position.y = y;
    sfSprite_move(entity->animation->sprite, entity->position);
    sfSprite_rotate(entity->animation->sprite, angle);
    return (0);
}

my_entity *spawn_entity(char *name_tag, my_textures_list *textures_list,
int sprites_nb)
{
    my_entity *entity = NULL;
    my_textures_list *temp = textures_list;
    sfVector2f size = {temp->full_width, temp->full_height};

    for (; temp; temp = temp->next) {
        if (!my_strcmp(temp->name_tag, name_tag)) {
            entity = malloc(sizeof(my_entity));
            entity->type = name_tag;
            entity->animation = malloc(sizeof(my_animation));
            set_animation(entity->animation, sprites_nb, &size, temp->path);
            entity->is_clicked = 0;
            break;
        }
    }
    return (entity);
}
