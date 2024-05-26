/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** destroy
*/

#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "animation.h"

int destroy_sprites_list(my_sprites_list *sprites_list)
{
    my_sprites_list *temp = NULL;

    while (sprites_list) {
        temp = sprites_list->next;
        free(sprites_list);
        sprites_list = temp;
    }
    return (0);
}
