/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** drawing_area
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/draw.h"

static void move_trail_coordinates(int *diff, sfVector2f *s, sfVector2f *pos_0,
sfVector2f *delta)
{
    int diff_2 = 4 * *diff;

    if (diff_2 > -delta->y) {
        *diff -= delta->y;
        pos_0->x += s->x;
    }
    if (diff_2 < delta->x) {
        *diff += delta->x;
        pos_0->y += s->y;
    }
}

static void draw_trail(sfVector2f pos_0, sfVector2f pos_1,
my_paint *p, pixels_t *pix)
{
    int is_square = 0;
    sfVector2f delta = {abs(pos_1.x - pos_0.x), abs(pos_1.y - pos_0.y)};
    sfVector2f s = {(pos_0.x < pos_1.x) ? 1 : -1, (pos_0.y < pos_1.y) ? 1 : -1};
    int diff = delta.x - delta.y;

    if ((p->values->mouse_tool == PENCIL && p->values->pencil_shape == SQUARE)
    || (p->values->mouse_tool == ERASER && p->values->eraser_shape == SQUARE))
        is_square = 1;
    while (pos_0.x != pos_1.x || pos_0.y != pos_1.y) {
        if (is_square)
            draw_square(pix, p, &(sfVector2i) {pos_0.x, pos_0.y});
        else
            draw_circle(pix, p, &(sfVector2i){pos_0.x, pos_0.y});
        move_trail_coordinates(&diff, &s, &pos_0, &delta);
    }
}

static void update_pixels_draw(sfVector2i *pos, my_paint *p, pixels_t *pix)
{
    pix->pos_y = pos->y - p->d->offset;
    pix->current_thickness = (p->values->mouse_tool == PENCIL) ?
    p->values->pencil_thickness : p->values->eraser_thickness;
    pix->current_color = (p->values->mouse_tool == PENCIL) ?
    p->values->pencil_color : sfWhite;

    pix->current = (sfVector2f){pos->x, pos->y};
    if (pix->current.x != 0 && pix->current.y != 0 &&
    pix->last.x != 0 && pix->last.y != 0) {
        draw_trail(pix->last, pix->current, p, pix);
        sfTexture_updateFromImage(p->d->drawing_area, p->d->area, 0, 0);
    }
    pix->last = (sfVector2f){pos->x, pos->y};
}

void draw_function(my_window *window, my_paint *p)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window->renderer);
    sfFloatRect rec = sfSprite_getGlobalBounds(p->d->sprite);

    pos.x *= p->w->ratio.x;
    pos.y *= p->w->ratio.y;
    if (sfFloatRect_contains(&rec, pos.x, pos.y)) {
        update_pixels_draw(&pos, p, p->pix);
    }
}

void destroy_drawing_area(drawing_area_t *d)
{
    sfImage_destroy(d->area);
    sfSprite_destroy(d->sprite);
    sfTexture_destroy(d->drawing_area);
    sfRectangleShape_destroy(d->rect_modal);
    sfCircleShape_destroy(d->circle_modal);
    sfSprite_destroy(d->pencil_sprite);
    sfSprite_destroy(d->eraser_sprite);
    free(d);
}
