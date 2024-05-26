/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** draw_utils.c
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/my.h"

void init_pixel_area(drawing_area_t *d, my_values *v, my_window *window)
{
    d->offset = 140;
    d->x = 660;
    d->sprite = sfSprite_create();
    d->area =
    sfImage_createFromColor(d->x, window->height - d->offset, sfWhite);
    d->drawing_area = sfTexture_createFromImage(d->area, NULL);
    d->rect_modal = sfRectangleShape_create();
    d->circle_modal = sfCircleShape_create();
    v->mouse_tool = PENCIL;
    v->pencil_thickness = 25;
    v->pencil_shape = SQUARE;
    v->eraser_thickness = 25;
    v->eraser_shape = SQUARE;
    v->pencil_color = sfBlack;
    sfSprite_setTexture(d->sprite, d->drawing_area, 0);
    sfSprite_setPosition(d->sprite, (sfVector2f){0, d->offset});
}

void init_pixels(pixels_t *p)
{
    p->pos_y = 0;
    p->temp_x = 0;
    p->temp_y = 0;
    p->i = 0;
    p->j = 0;
    p->current = (sfVector2f){0};
    p->last = (sfVector2f){0};
}
