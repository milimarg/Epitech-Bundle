/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** animations
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "animation.h"
#include "../window/window.h"

my_sprites_list *init_sprites_list(void)
{
    my_sprites_list *sprites_list = NULL;

    return (sprites_list);
}

void add_sprite(my_sprites_list **sprites_list, char *type, char *path,
sfVector2f *sizes)
{
    my_sprites_list *element = malloc(sizeof(my_sprites_list));

    element->type = type;
    element->path = path;
    element->spriteFullWidth = sizes->x;
    element->spriteFullHeight = sizes->y;
    element->next = *sprites_list;
    *sprites_list = element;
    return;
}

int set_animation(my_animation *anim, int moves_nb, sfVector2f *size,
char *path)
{
    anim->i = 0;
    anim->sprite_nb = moves_nb;
    anim->size = *size;
    anim->path = path;
    anim->has_sprite_been_defined = 0;
    anim->textures = malloc(sizeof(sfTexture *) * anim->sprite_nb);
    for (int i = 0; i < anim->sprite_nb; i++)
        anim->textures[i] = NULL;
    anim->sprite = sfSprite_create();
    return (0);
}
