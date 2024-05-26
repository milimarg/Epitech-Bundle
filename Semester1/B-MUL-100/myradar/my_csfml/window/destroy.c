/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** destroy
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "window.h"

int destroy_window(my_window *window)
{
    sfRenderWindow_destroy(window->renderer);
    sfClock_destroy(window->clock);
    free(window);
    return (0);
}

int destroy_background(my_background *background)
{
    free(background);
    return (0);
}
