/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** shapes
*/

#include <SFML/Audio.h>
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/draw.h"

static void fill_circle(sfVector2i *pos, pixels_t *pix, drawing_area_t *d,
my_window *window)
{
    sfVector2f p_left = {0};
    sfVector2f p_right = {0};
    sfVector2f f_pos = {0};

    for (size_t i = 1; i < (d->curr_points_nb / 2); i++) {
        p_left = sfCircleShape_getPoint(d->circle_modal, d->curr_points_nb - i);
        p_right = sfCircleShape_getPoint(d->circle_modal, i);
        for (; p_left.x < p_right.x; p_left.x++) {
            f_pos.x = p_left.x + pos->x - pix->current_thickness;
            f_pos.y = p_left.y + pos->y - d->offset - pix->current_thickness;
            check_point_pos(&f_pos, d, pix, window);
        }
    }
}

void draw_circle(pixels_t *pix, my_paint *p, sfVector2i *pos)
{
    sfCircleShape_setRadius(p->d->circle_modal, pix->current_thickness);
    p->d->curr_points_nb = pix->current_thickness * pix->current_thickness;
    if (pix->current_thickness <= 6)
        p->d->curr_points_nb *= 2;
    sfCircleShape_setPointCount(p->d->circle_modal, p->d->curr_points_nb);
    fill_circle(pos, pix, p->d, p->w);
}

static void condition_draw_pixels(pixels_t *p, drawing_area_t *d,
sfVector2i *pos, my_window *window)
{
    p->temp_x = (pos->x < p->current_thickness) ? pos->x : pos->x - p->i;
    p->temp_y = (pos->y < (d->offset + p->current_thickness)) ? p->pos_y :
    p->pos_y - p->j;
    if (anti_glitch_square(p, d, window))
        return;
    sfImage_setPixel(d->area, p->temp_x, p->temp_y, p->current_color);
    p->temp_x = (pos->x > d->x - p->current_thickness) ? pos->x : pos->x + p->i;
    if (anti_glitch_square(p, d, window))
        return;
    sfImage_setPixel(d->area, p->temp_x, p->temp_y, p->current_color);
    p->temp_x = (pos->x < p->current_thickness) ? pos->x : pos->x - p->i;
    p->temp_y = (pos->y > (window->height - p->current_thickness)) ? p->pos_y :
    p->pos_y + p->j;
    if (anti_glitch_square(p, d, window))
        return;
    sfImage_setPixel(d->area, p->temp_x, p->temp_y, p->current_color);
    p->temp_x = (pos->x > d->x - p->current_thickness) ? pos->x : pos->x + p->i;
    if (anti_glitch_square(p, d, window))
        return;
    sfImage_setPixel(d->area, p->temp_x, p->temp_y, p->current_color);
}

void draw_square(pixels_t *pix, my_paint *p, sfVector2i *pos)
{
    for (pix->i = 0; pix->i < pix->current_thickness; pix->i++) {
        for (pix->j = 0; pix->j < pix->current_thickness; pix->j++) {
            condition_draw_pixels(pix, p->d, pos, p->w);
        }
    }
}
