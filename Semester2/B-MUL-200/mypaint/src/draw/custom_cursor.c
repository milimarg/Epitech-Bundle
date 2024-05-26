/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** custom_cursor.c
*/

#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"

void create_cursor(drawing_area_t *d, side_menu_t *m)
{
    sfVector2f origin = {0};

    d->pencil_sprite = sfSprite_create();
    d->eraser_sprite = sfSprite_create();
    sfSprite_setTexture(d->pencil_sprite, m->pencil_logo, sfTrue);
    sfSprite_setTexture(d->eraser_sprite, m->eraser_logo, sfTrue);
    origin = (sfVector2f){64 / 2, 64 / 2};
    sfSprite_setOrigin(d->pencil_sprite, origin);
    origin = (sfVector2f){64 / 2, 44 / 2};
    sfSprite_setOrigin(d->pencil_sprite, origin);
}

static void display_tool(my_paint *p, sfVector2f *n_pos)
{
    if (p->values->mouse_tool == PENCIL) {
        sfSprite_setPosition(p->d->pencil_sprite, *n_pos);
        sfRenderWindow_drawSprite(p->w->renderer, p->d->pencil_sprite, NULL);
    } else {
        sfSprite_setPosition(p->d->eraser_sprite, *n_pos);
        sfRenderWindow_drawSprite(p->w->renderer, p->d->eraser_sprite, NULL);
    }
}

void display_cursor(my_paint *p)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(p->w->renderer);
    sfFloatRect rec = sfSprite_getGlobalBounds(p->d->sprite);
    sfVector2f n_pos = {0};

    pos.x *= p->w->ratio.x;
    pos.y *= p->w->ratio.y;
    if (sfFloatRect_contains(&rec, pos.x, pos.y)) {
        sfRenderWindow_setMouseCursorVisible(p->w->renderer, sfFalse);
        n_pos = (sfVector2f){pos.x, pos.y};
        display_tool(p, &n_pos);
    } else
        sfRenderWindow_setMouseCursorVisible(p->w->renderer, sfTrue);
}
