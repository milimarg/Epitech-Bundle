/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** events_utils.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/openfile.h"

int detect_click_on_button(my_paint *p, int i)
{
    char *element = NULL;

    update_button_state(p->open->window, p->open->buttons[i]);
    sfRectangleShape_setFillColor(p->open->buttons[i]->shape,
    p->btn_colors[p->open->buttons[i]->state]);
    if (IS_CLICK(p->open->buttons[i]->state) && !p->open->is_dir_clicked) {
        p->open->is_dir_clicked = 1;
        p->open->fp_index = 0;
        element = (char *)sfText_getString(p->open->buttons[i]->text);
        get_full_filepath(p, element);
        if (!check_file_is_valid(p))
            return (0);
        free(p->open->current_path);
        return (refresh_current_dir(p, element));
    }
    if (p->open->is_dir_clicked && !sfMouse_isButtonPressed(sfMouseLeft))
        p->open->is_dir_clicked = 0;
    return (0);
}

static void update_positions(open_popup *o, int is_scrolling_down)
{
    o->fp_index = (is_scrolling_down) ? o->fp_index + 1 : o->fp_index - 1;
    sfVector2f pos = {0, o->fp_index * o->scroll_rect.height};
    sfRectangleShape_setPosition(o->scroll_bar, pos);
    for (int i = 0; i < o->buttons_nb; i++) {
        pos = sfRectangleShape_getPosition(o->buttons[i]->shape);
        pos.y = (is_scrolling_down) ? pos.y - o->buttons[i]->rect.height :
        pos.y + o->buttons[i]->rect.height;
        sfRectangleShape_setPosition(o->buttons[i]->shape, pos);
        sfText_setPosition(o->buttons[i]->text, pos);
    }
}

void scroll_in_directory_fp(open_popup *o, int is_scrolling_down)
{
    if ((o->fp_index + o->max_buttons < o->buttons_nb && is_scrolling_down) ||
        (o->fp_index > 0 && !is_scrolling_down)) {
        update_positions(o, is_scrolling_down);
    }
}

int display_buttons_events_fp(open_popup *o, my_paint *p)
{
    int end = (o->buttons_nb >= o->max_buttons) ? o->fp_index + o->max_buttons :
    o->buttons_nb;

    for (int i = o->fp_index; i < end; i++) {
        if (detect_click_on_button(p, i))
            return (1);
        if (o->buttons_nb > o->max_buttons)
            sfRenderWindow_drawRectangleShape(o->window->renderer,
            o->scroll_bar, NULL);
        sfRenderWindow_drawRectangleShape(o->window->renderer,
        o->buttons[i]->shape, NULL);
        sfRenderWindow_drawText(o->window->renderer, o->buttons[i]->text, NULL);
    }
    return (0);
}
