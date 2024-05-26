/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** window
*/

#include <stdlib.h>
#include "window.h"

void clear_window(my_window *window)
{
    sfRenderWindow_clear(window->renderer, sfBlack);
}

void refresh_window(my_window *window)
{
    sfRenderWindow_display(window->renderer);
}

my_window *create_window(char *title, int width, int height)
{
    my_window *window = malloc(sizeof(my_window));

    window->width = width;
    window->height = height;
    window->bitsPerPixel = 32;
    window->renderer = sfRenderWindow_create(
    (sfVideoMode){window->width, window->height, window->bitsPerPixel}, title,
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window->renderer, 60);
    window->clock = sfClock_create();
    return (window);
}

sfVector2u update_window_ratio(my_window *window)
{
    sfVector2u size = sfRenderWindow_getSize(window->renderer);

    window->ratio.x = (double)window->width / (double)size.x;
    window->ratio.y = (double)window->height / (double)size.y;
    return (size);
}
