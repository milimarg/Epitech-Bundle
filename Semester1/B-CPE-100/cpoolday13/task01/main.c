/*
** EPITECH PROJECT, 2022
** CPOOL_Day13_task01
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

sfRenderWindow *create_window(int width, int height, char const *title);

int main(void)
{
    sfRenderWindow *window = create_window(800, 600, "CSFML");

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
