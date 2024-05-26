/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** entity.c
*/

#include <stdlib.h>
#include "csfml_structs.h"
#include "csfml_protos.h"

int spawn_entity(entity_t *entity, char *type, sprites_list_t *sprites_list,
int sprites_nb)
{
    sprites_list_t *temp = sprites_list;
    int has_found_sprite = 0;
    sfVector2i size;

    while (temp) {
        if (!my_strcmp(temp->type, type)) {
            entity->type = type;
            size.x = temp->spriteFullWidth;
            size.y = temp->spriteFullHeight;
            entity->animation = malloc(sizeof(animation_t));
            set_animation(entity->animation, sprites_nb, &size, temp->path);
            entity->is_clicked = 0;
            has_found_sprite = 1;
        }
        temp = temp->next;
    }
    return (has_found_sprite);
}

int set_spawnpoint(entity_t *entity, float x, float y, float angle)
{
    float last_angle = sfSprite_getRotation(entity->animation->sprite);

    entity->position.x = x;
    entity->position.y = y;
    sfSprite_setPosition(entity->animation->sprite, entity->position);
    sfSprite_rotate(entity->animation->sprite, (last_angle * (-1)));
    sfSprite_rotate(entity->animation->sprite, angle);
    return (0);
}

int set_sound(entity_t *entity, char *filepath)
{
    entity->sound = sfSound_create();
    entity->sound_buffer = sfSoundBuffer_createFromFile(filepath);
    sfSound_setBuffer(entity->sound, entity->sound_buffer);
    return (0);
}

int detect_click_on_entity(entity_t *entity, window_t *window, mouse_t *mouse)
{
    sfVector2f entity_pos = sfSprite_getPosition(entity->animation->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->renderer);
    int is_mouse_over_entity_x = (
        entity_pos.x <= mouse_pos.x +
        (entity->animation->size.x / entity->animation->sprite_nb) &&
        entity_pos.x >= mouse_pos.x -
        (entity->animation->size.x / entity->animation->sprite_nb));
    int is_mouse_over_entity_y = (
        entity_pos.y <= mouse_pos.y + entity->animation->size.y &&
        entity_pos.y >= mouse_pos.y - entity->animation->size.y);

    if (is_mouse_over_entity_x && is_mouse_over_entity_y && mouse->left_clicked)
        if (!entity->is_clicked)
            entity->is_clicked = 1;
    return (0);
}

int move_entity(entity_t *entity, float x, float y, float angle)
{
    entity->position.x = x;
    entity->position.y = y;
    sfSprite_move(entity->animation->sprite, entity->position);
    sfSprite_rotate(entity->animation->sprite, angle);
    return (0);
}
