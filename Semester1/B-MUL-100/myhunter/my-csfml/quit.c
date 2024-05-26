/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** quit.c
*/

#include "csfml_structs.h"

int is_quit(sfEvent *event, window_t *window)
{
    if (event->type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window->renderer);
    return (0);
}
