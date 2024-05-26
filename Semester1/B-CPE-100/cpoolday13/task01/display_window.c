/*
** EPITECH PROJECT, 2022
** CPOOL_Day13
** File description:
** display_window.c
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

sfRenderWindow *create_window(int width, int height, char const *title)
{
    sfRenderWindow *Window;
    sfVideoMode mode;

    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = 32;
    Window = sfRenderWindow_create(mode, title, sfResize | sfClose, NULL);
    return (Window);
}
