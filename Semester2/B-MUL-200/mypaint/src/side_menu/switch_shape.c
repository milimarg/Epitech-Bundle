/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** switch_shape
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/my.h"
#include "../../include/sidemenu.h"

void square(void *values)
{
    my_paint *p = values;

    sfRectangleShape_setOutlineColor(p->m->b[0]->shape, sfRed);
    sfCircleShape_setOutlineColor(p->m->btn_tool_circle, sfWhite);
    if (p->values->mouse_tool == PENCIL)
        p->values->pencil_shape = SQUARE;
    else
        p->values->eraser_shape = SQUARE;
}

void circle(void *values)
{
    my_paint *p = values;

    sfRectangleShape_setOutlineColor(p->m->b[0]->shape, sfWhite);
    sfCircleShape_setOutlineColor(p->m->btn_tool_circle, sfRed);
    if (p->values->mouse_tool == PENCIL)
        p->values->pencil_shape = CIRCLE;
    else
        p->values->eraser_shape = CIRCLE;
}
