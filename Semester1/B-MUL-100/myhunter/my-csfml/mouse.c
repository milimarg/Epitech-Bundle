/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** mouse.c
*/

#include "csfml_structs.h"

int get_mouse(window_t *window, mouse_t *mouse)
{
    mouse->coor = sfMouse_getPositionRenderWindow(window->renderer);
    mouse->left_clicked = sfMouse_isButtonPressed(sfMouseLeft);
    mouse->right_clicked = sfMouse_isButtonPressed(sfMouseRight);
    return (0);
}
