/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** temp.c
*/

#include "csfml_structs.h"

int ootb_x(int left_or_right, entity_t *entity, window_t *window)
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

int ootb_y(int up_or_down, entity_t *entity, window_t *window)
{
    int o = 0;
    int sprite_size = entity->animation->size.y;

    if (!up_or_down)
        o = sprite_size * (-1);
    else
        o = window->height + sprite_size;
    return (o);
}

int destroy_entity_elements(sfTexture *texture, sfSprite *sprite,
sfSound *sound, sfSoundBuffer *sound_buffer)
{
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    sfSoundBuffer_destroy(sound_buffer);
    sfSound_destroy(sound);
    return (0);
}
