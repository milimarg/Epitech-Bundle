/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** slider
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/my.h"

static void convert_slider_to_string(int number, my_paint *p)
{
    if (number <= 9) {
        p->m->text[0] = ' ';
        p->m->text[1] = number + '0';
    } else {
        p->m->text[0] = (number / 10) + '0';
        p->m->text[1] = (number % 10) + '0';
    }
    sfText_setString(p->m->b[2]->text, p->m->text);
}

void set_slider_value(my_paint *p)
{
    int current_thickness = (p->values->mouse_tool == PENCIL) ?
    p->values->pencil_thickness : p->values->eraser_thickness;
    double delta_size = (double)current_thickness / (double)p->m->end_value;
    sfVector2f size = {p->m->b[3]->rect.width, delta_size *
    p->m->b[3]->rect.height};

    sfRectangleShape_setSize(p->m->b[3]->shape, size);
    convert_slider_to_string(current_thickness, p);
}

static void calc_values_utils(my_paint *p, sfVector2f *slider_size,
int *tool_size)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(p->w->renderer);
    int delta_size = 0;
    double percentage = 0;

    pos.x *= p->w->ratio.x;
    pos.y *= p->w->ratio.y;
    delta_size = pos.y - p->m->b[3]->rect.top;
    percentage = (double)delta_size / (double)p->m->b[3]->rect.height;
    percentage = (percentage < 0) ? 0 : percentage;
    percentage = (percentage > 1) ? 1 : percentage;
    slider_size->x = p->m->b[3]->rect.width;
    if (p->w->ratio.y != 0)
        slider_size->y = (p->m->b[3]->rect.height * percentage) / p->w->ratio.y;
    *tool_size = p->m->end_value * percentage;
}

void calc_slider_value(void *values)
{
    my_paint *p = values;
    sfVector2f slider_size = {0};
    int tool_size = 0;

    calc_values_utils(p, &slider_size, &tool_size);
    convert_slider_to_string(tool_size, p);
    sfRectangleShape_setSize(p->m->b[3]->shape, slider_size);
    if (p->values->mouse_tool == PENCIL)
        p->values->pencil_thickness = tool_size;
    else
        p->values->eraser_thickness = tool_size;
}

void handle_slider(my_paint *p, my_window *window)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(p->m->b[2]->shape);
    sfVector2i pos = sfMouse_getPositionRenderWindow(window->renderer);
    int click = sfMouse_isButtonPressed(sfMouseLeft);

    pos.x *= window->ratio.x;
    pos.y *= window->ratio.y;
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && click &&
    !p->m->is_slider_selected) {
        p->m->is_slider_selected = 1;
        sfRectangleShape_setOutlineThickness(p->m->b[2]->shape, 1);
    }
    if (!sfFloatRect_contains(&rect, pos.x, pos.y) && click &&
    p->m->is_slider_selected) {
        p->m->is_slider_selected = 0;
        sfRectangleShape_setOutlineThickness(p->m->b[2]->shape, 0);
    }
    update_button_state(window, p->m->b[2]);
    if (IS_CLICK(p->m->b[2]->state)) {
        p->m->b[2]->function(p);
    }
}
