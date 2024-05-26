/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** shape_utils.c
*/

#include <SFML/Audio.h>
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"

int check_point_pos(sfVector2f *f_pos, drawing_area_t *d, pixels_t *pix,
my_window *window)
{
    if (f_pos->x > 0 && f_pos->x < d->x && f_pos->y > 0 &&
        f_pos->y < (window->height - d->offset)) {
        sfImage_setPixel(d->area, f_pos->x, f_pos->y, pix->current_color);
    }
}

int anti_glitch_square(pixels_t *p, drawing_area_t *d, my_window *window)
{
    return (p->temp_x < 0 || p->temp_x > d->x || p->temp_y < 0 ||
            p->temp_y >= (window->height - d->offset));
}
