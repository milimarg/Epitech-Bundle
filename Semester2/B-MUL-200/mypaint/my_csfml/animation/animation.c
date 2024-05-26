/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** animations
*/

#include <stdlib.h>
#include "animation.h"

my_textures_list *init_textures_list(void)
{
    return (NULL);
}

int add_texture(my_textures_list **textures_list, char *name_tag, char *path,
sfIntRect *rectangle)
{
    my_textures_list *element = malloc(sizeof(my_textures_list));

    element->name_tag = name_tag;
    element->path = path;
    element->width = rectangle->width;
    element->height = rectangle->height;
    element->texture = sfTexture_createFromFile(element->path, rectangle);
    element->next = *textures_list;
    *textures_list = element;
    return (0);
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

void update_animation(my_animation *animation)
{
    sfSprite_setTexture(animation->sprite,
    animation->textures[animation->i], sfTrue);
    animation->i = (animation->i == animation->sprite_nb - 1)
    ? 0 : animation->i + 1;
}
