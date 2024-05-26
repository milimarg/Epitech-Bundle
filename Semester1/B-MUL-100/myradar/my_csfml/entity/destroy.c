/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** destroy
*/

#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "../window/window.h"
#include "../animation/animation.h"
#include "entity.h"

int destroy_entity(my_entity *entity)
{
    for (int i = 0; i < entity->animation->sprite_nb; i++)
        sfTexture_destroy(entity->animation->textures[i]);
    free(entity->animation->textures);
    sfSprite_destroy(entity->animation->sprite);
    free(entity->animation);
    free(entity);
    return (0);
}
