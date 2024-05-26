/*
** EPITECH PROJECT, 2022
** CPOOL_Day13_task02
** File description:
** main.c
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include "../include/my_struct.h"

sfRenderWindow *create_window(int width, int height, char const *title);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color);

int main(void)
{
    int width = 800;
    int height = 600;
    framebuffer_t *framebuffer;
    sfSprite *sprite;

    sfRenderWindow *window = create_window(width, height, "CPOOL_Task02");
    framebuffer = framebuffer_create(width, height);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
