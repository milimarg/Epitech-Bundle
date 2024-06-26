/*
** EPITECH PROJECT, 2023
** my_csfml_container
** File description:
** button_utils.c
*/

#include <SFML/Graphics.h>
#include "../window/window.h"
#include "button.h"

void update_button_state(my_window *window, my_button *button)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->shape);
    sfVector2i pos = sfMouse_getPositionRenderWindow(window->renderer);
    int hover_status = 0;
    int click_status = sfMouse_isButtonPressed(sfMouseLeft);

    pos.x *= window->ratio.x;
    pos.y *= window->ratio.y;
    hover_status = sfFloatRect_contains(&rect, pos.x, pos.y);
    if (!hover_status && !click_status)
        button->state = NONE;
    if (hover_status && !click_status)
        button->state = HOVER;
    if (hover_status && click_status)
        button->state = CLICKED;
}
