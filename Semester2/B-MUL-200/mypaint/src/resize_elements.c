/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** resize_elements.c
*/

#include <SFML/Graphics.h>
#include "../my_csfml/window/window.h"
#include "../my_csfml/button/button.h"
#include "../include/structs.h"

static void update_buttons_sizes(my_paint *p, int i)
{
    sfVector2f pos = {0};

    for (int j = 0; j < p->dp[i]->buttons_nb; j++) {
        sfRectangleShape_setScale(p->dp[i]->buttons[j]->shape,
        p->w->ratio);
        pos.x = p->dp[i]->buttons[j]->rect.left * p->w->ratio.x;
        pos.y = p->dp[i]->buttons[j]->rect.top * p->w->ratio.y;
        sfRectangleShape_setPosition(p->dp[i]->buttons[j]->shape, pos);
        sfText_setScale(p->dp[i]->buttons[j]->text, p->w->ratio);
        sfText_setPosition(p->dp[i]->buttons[j]->text, pos);
    }
}

static void resize_side_menu(my_paint *p, sfVector2u *ns, sfVector2f *pos)
{

    sfSprite_setScale(p->arr_color->sprite_col, p->w->ratio);
    pos->x = (ns->x - 140) * p->w->ratio.x;
    pos->y = 0;
    sfSprite_setPosition(p->arr_color->sprite_col, *pos);
    sfSprite_setScale(p->m->pencil_sprite, p->w->ratio);
    sfSprite_setScale(p->m->eraser_sprite, p->w->ratio);
    pos->x = (ns->x - (p->w->width - p->m->pos.x)) * p->w->ratio.x;
    pos->y = ((ns->y * p->w->ratio.y) - (p->w->height - p->m->pos.y));
    sfSprite_setPosition(p->m->pencil_sprite, *pos);
    sfSprite_setPosition(p->m->eraser_sprite, *pos);
    for (int i = 0; p->m->b[i] != NULL; i++) {
        sfRectangleShape_setScale(p->m->b[i]->shape, p->w->ratio);
        sfText_setScale(p->m->b[i]->text, p->w->ratio);
        pos->x = (ns->x - (p->w->width - p->m->b[i]->rect.left)) *
        p->w->ratio.x;
        pos->y = ((ns->y * p->w->ratio.y) -
        (p->w->height - p->m->b[i]->rect.top));
        sfRectangleShape_setPosition(p->m->b[i]->shape, *pos);
    }
}

static void resize_2_side_menu(my_paint *p, sfVector2u *ns, sfVector2f *pos)
{
    sfCircleShape_setScale(p->m->btn_tool_circle, p->w->ratio);
    pos->x = (ns->x - (p->w->width - p->m->b[1]->rect.left)) * p->w->ratio.x;
    pos->y = ((ns->y * p->w->ratio.y) - (p->w->height - p->m->b[1]->rect.top));
    sfCircleShape_setPosition(p->m->btn_tool_circle, *pos);
    pos->x = (ns->x - (p->w->width - p->m->slider_text_pos.x)) * p->w->ratio.x;
    pos->y = ((ns->y * p->w->ratio.y) -
    (p->w->height - p->m->slider_text_pos.y));
    sfText_setPosition(p->m->b[2]->text, *pos);
}

void update_sizes_main(my_paint *p)
{
    sfVector2u ns = update_window_ratio(p->w);
    sfVector2f pos = {0};

    for (int i = 0; i < p->dp_number; i++) {
        sfRectangleShape_setScale(p->dp[i]->shape, p->w->ratio);
        pos.x = p->dp[i]->rect.left * p->w->ratio.x;
        pos.y = p->dp[i]->rect.top * p->w->ratio.y;
        sfRectangleShape_setPosition(p->dp[i]->shape, pos);
        sfText_setScale(p->dp[i]->text, p->w->ratio);
        sfText_setPosition(p->dp[i]->text, pos);
        update_buttons_sizes(p, i);
    }
    resize_side_menu(p, &ns, &pos);
    resize_2_side_menu(p, &ns, &pos);
    sfSprite_setScale(p->d->pencil_sprite, p->w->ratio);
    sfSprite_setScale(p->d->eraser_sprite, p->w->ratio);
}
