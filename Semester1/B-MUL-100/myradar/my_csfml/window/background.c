/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** background
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "window.h"

void set_offset_background(my_background *ptr, int x_offset, int y_offset)
{
    sfIntRect rectangle = {0};

    ptr->x_offset = x_offset;
    ptr->y_offset = y_offset;
    rectangle.width = ptr->width;
    rectangle.height = ptr->height;
    rectangle.left = ptr->x_offset;
    rectangle.top = ptr->y_offset;
    ptr->sprite = sfSprite_create();
    ptr->texture = sfTexture_createFromFile(ptr->path, &rectangle);
    sfSprite_setTexture(ptr->sprite, ptr->texture, sfTrue);
}

void display_background(my_window *window, my_background *background)
{
    sfRenderWindow_drawSprite(window->renderer, background->sprite, NULL);
}

my_background *init_background(char *path, int width, int height)
{
    my_background *background = malloc(sizeof(my_background));

    background->path = path;
    background->width = width;
    background->height = height;
    background->finish = set_offset_background;
    background->display = display_background;
    background->destroy = destroy_background;
    return (background);
}
