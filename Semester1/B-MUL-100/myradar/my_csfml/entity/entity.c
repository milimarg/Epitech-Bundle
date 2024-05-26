/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** entity
*/

#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "../window/window.h"
#include "../animation/animation.h"
#include "entity.h"

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

my_entity *spawn_entity(char *type, my_sprites_list *sprites_list,
int sprites_nb)
{
    my_entity *entity = NULL;
    my_sprites_list *temp = sprites_list;

    for (; temp; temp = temp->next) {
        if (!my_strcmp(temp->type, type)) {
            entity = malloc(sizeof(my_entity));
            entity->type = type;
            entity->animation = malloc(sizeof(my_animation));
            set_animation(entity->animation, sprites_nb,
            &((sfVector2f){temp->spriteFullWidth, temp->spriteFullHeight}),
            temp->path);
            entity->is_clicked = 0;
            entity->add_moves = add_moves;
            entity->update = update_animation;
            entity->display = display_entity;
            entity->destroy = destroy_entity;
            break;
        }
    }
    return (entity);
}
