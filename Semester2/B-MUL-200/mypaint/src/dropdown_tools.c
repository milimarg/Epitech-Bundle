/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** dropdown_tools.c
*/

#include "../my_csfml/button/button.h"
#include "../include/structs.h"
#include "../include/sidemenu.h"

void set_pencil(void *values)
{
    my_paint *p = values;

    p->values->mouse_tool = PENCIL;
    set_slider_value(p);
    sfRectangleShape_setOutlineColor(p->m->b[0]->shape,
    (p->values->pencil_shape == SQUARE) ? sfRed : sfWhite);
    sfCircleShape_setOutlineColor(p->m->btn_tool_circle,
    (p->values->pencil_shape == CIRCLE) ? sfRed : sfWhite);
}

void set_eraser(void *values)
{
    my_paint *p = values;

    p->values->mouse_tool = ERASER;
    set_slider_value(p);
    sfRectangleShape_setOutlineColor(p->m->b[0]->shape,
    (p->values->eraser_shape == SQUARE) ? sfRed : sfWhite);
    sfCircleShape_setOutlineColor(p->m->btn_tool_circle,
    (p->values->eraser_shape == CIRCLE) ? sfRed : sfWhite);
}
