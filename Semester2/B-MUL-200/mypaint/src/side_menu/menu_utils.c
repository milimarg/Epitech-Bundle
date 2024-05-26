/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** menu_utils
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/my.h"
#include "../../include/sidemenu.h"

static void init_menu_object(side_menu_t *m)
{
    m->pos = (sfVector2f){700, 160};
    m->pencil_logo = sfTexture_createFromFile("./assets/pencil.png", NULL);
    m->eraser_logo = sfTexture_createFromFile("./assets/eraser.png", NULL);
    m->pencil_sprite = sfSprite_create();
    m->eraser_sprite = sfSprite_create();
    sfSprite_setTexture(m->pencil_sprite, m->pencil_logo, sfTrue);
    sfSprite_setPosition(m->pencil_sprite, m->pos);
    sfSprite_setTexture(m->eraser_sprite, m->eraser_logo, sfTrue);
    sfSprite_setPosition(m->eraser_sprite, m->pos);
    m->slider_bg = (sfColor){56, 56, 56, 255};
    m->slider_fill = (sfColor){83, 114, 142, 255};
    m->slider_outline = (sfColor){197, 14, 210, 255};
    m->b = init_buttons_array(4);
    m->b[0] = add_button(&(sfIntRect){690, 550, 25, 25}, &sfTransparent,
    &square, "");
    m->b[1] = add_button(&(sfIntRect){750, 550, 25, 25}, &sfTransparent,
    &circle, "");
}

void init_side_menu_buttons(my_paint *p)
{
    int offset_slider = 0;

    p->m->slider = (sfIntRect){700, 280, 40, 150};
    p->m->slider_text_pos = (sfVector2f){705,
    p->m->slider.top + p->m->slider.height + 20};
    sfRectangleShape_setOutlineColor(p->m->b[0]->shape,
    (p->values->pencil_shape == SQUARE) ? sfRed : sfWhite);
    sfRectangleShape_setOutlineThickness(p->m->b[1]->shape, 0);
    offset_slider = (p->w->width - 660 - p->m->slider.width) / 2;
    p->m->slider.left = 660 + offset_slider;
    p->m->b[2] = add_button(&p->m->slider, &p->m->slider_bg,
    &calc_slider_value, "50px");
    sfRectangleShape_setOutlineColor(p->m->b[2]->shape,
    p->m->slider_outline);
    sfRectangleShape_setOutlineThickness(p->m->b[2]->shape, 0);
    sfText_setFont(p->m->b[2]->text, p->font);
    sfText_setPosition(p->m->b[2]->text, p->m->slider_text_pos);
    p->m->b[3] = add_button(&p->m->slider, &p->m->slider_fill, &dummy, "");
    sfRectangleShape_setOutlineThickness(p->m->b[3]->shape, 0);
    p->m->b[4] = NULL;
}

void init_side_menu(my_paint *p)
{
    char *text = "00px";

    init_menu_object(p->m);
    p->m->btn_tool_circle = sfCircleShape_create();
    sfCircleShape_setFillColor(p->m->btn_tool_circle, sfTransparent);
    sfCircleShape_setOutlineThickness(p->m->btn_tool_circle, 1);
    sfCircleShape_setOutlineColor(p->m->btn_tool_circle,
    (p->values->pencil_shape == CIRCLE) ? sfRed : sfWhite);
    sfCircleShape_setPosition(p->m->btn_tool_circle, (sfVector2f){750, 550});
    sfCircleShape_setRadius(p->m->btn_tool_circle, 12.5);
    init_side_menu_buttons(p);
    p->m->end_value = 50;
    p->m->text = malloc(sizeof(char) * 5);
    for (int i = 0; i < 4; i++)
        p->m->text[i] = text[i];
    p->m->text[4] = 0;
    p->m->b[4] = NULL;
    p->m->is_slider_selected = 0;
}
