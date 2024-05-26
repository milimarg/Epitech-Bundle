/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** animations.c
*/

#include <stdlib.h>
#include "csfml_structs.h"

int get_mouse(window_t *window, mouse_t *mouse);

sprites_list_t *add_sprite(sprites_list_t *sprites_list,
sprites_list_t *element, char **type_and_path, sfVector2i *sizes)
{
    element = malloc(sizeof(*element));
    element->type = type_and_path[0];
    element->path = type_and_path[1];
    element->spriteFullWidth = sizes->x;
    element->spriteFullHeight = sizes->y;
    element->next = sprites_list;
    sprites_list = element;
    return (sprites_list);
}

int set_animation(animation_t *anim, int sprite_nb, sfVector2i *size,
char *path)
{
    anim->i = 0;
    anim->sprite_nb = sprite_nb;
    anim->size = *size;
    anim->path = path;
    anim->has_sprite_been_defined = 0;
    anim->texture = NULL;
    anim->sprite = sfSprite_create();
    return (0);
}

int update_animation(animation_t *anim, int height_of_sprite, int order)
{
    sfIntRect rectangle;

    rectangle.width = anim->size.x / anim->sprite_nb;
    rectangle.height = height_of_sprite;
    rectangle.left = rectangle.width * anim->i;
    rectangle.top = height_of_sprite * order;
    anim->texture = sfTexture_createFromFile(anim->path, &rectangle);
    sfSprite_setTexture(anim->sprite, anim->texture, sfTrue);
    anim->i = (anim->i == anim->sprite_nb - 1) ? 0 : anim->i + 1;
    if (!anim->has_sprite_been_defined)
        anim->has_sprite_been_defined = 1;
    return (0);
}
