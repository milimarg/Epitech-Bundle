/*
** EPITECH PROJECT, 2023
** my_csfml
** File description:
** buttons
*/

#include <string.h>
#include <stdlib.h>
#include "button.h"

my_button **init_buttons_array(unsigned int buttons_number)
{
    my_button **buttons = malloc(sizeof(my_button *) * (buttons_number + 1));

    return (buttons);
}

static int set_button_rectangle_shape(my_button *button, char *display_name)
{
    sfVector2f pos = {button->rect.left, button->rect.top};
    sfVector2f text_pos = {button->rect.left + 5, button->rect.top};
    sfVector2f size = {button->rect.width, button->rect.height};

    button->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(button->shape, size);
    sfRectangleShape_setOutlineColor(button->shape, sfBlack);
    sfRectangleShape_setOutlineThickness(button->shape, 1);
    sfRectangleShape_setFillColor(button->shape, button->color);
    sfRectangleShape_setPosition(button->shape, pos);
    button->text = sfText_create();
    sfText_setPosition(button->text, text_pos);
    sfText_setString(button->text, display_name);
    sfText_setCharacterSize(button->text, 25);
    return (0);
}

my_button* add_button(sfIntRect *rectangle, sfColor *color,
void (*function)(void *values), char *display_name)
{
    my_button *button = malloc(sizeof(my_button));

    button->rect = *rectangle;
    button->color = *color;
    button->function = function;
    set_button_rectangle_shape(button, display_name);
    button->state = NONE;
    button->is_clicked = 0;
    return (button);
}

int destroy_buttons_array(my_button **buttons)
{
    for (int i = 0; buttons[i] != NULL; i++) {
        sfRectangleShape_destroy(buttons[i]->shape);
        sfText_destroy(buttons[i]->text);
        free(buttons[i]);
    }
    free(buttons);
    return (0);
}

void display_buttons(my_button **buttons, my_window *window)
{
    for (int i = 0; buttons[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(window->renderer, buttons[i]->shape,
        NULL);
    }
}
