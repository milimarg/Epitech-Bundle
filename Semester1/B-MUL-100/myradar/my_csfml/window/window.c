/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** window
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
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
    window->clear = clear_window;
    window->refresh = refresh_window;
    window->destroy = destroy_window;
    return (window);
}
