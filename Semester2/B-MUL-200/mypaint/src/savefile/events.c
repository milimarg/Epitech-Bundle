/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** savefile_popup_events.c uf
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/savefile.h"

static void update_sizes(save_popup *s)
{
    update_window_ratio(s->window);
    for (int i = 0; i < s->buttons_nb; i++) {
        sfRectangleShape_setScale(s->buttons[i]->shape, s->window->ratio);
        sfText_setScale(s->buttons[i]->text, s->window->ratio);
    }
    for (int i = 0; i < s->ext_nb; i++) {
        sfText_setScale(s->ext_names[i], s->window->ratio);
    }
}

static int update_buttons_color(int i, my_paint *p)
{
    if (i < 3) {
        sfRectangleShape_setFillColor(p->save->buttons[i]->shape,
        p->btn_colors[p->save->buttons[i]->state]);
        sfRenderWindow_drawText(p->save->window->renderer,
        p->save->ext_names[i], NULL);
    } else
        sfRectangleShape_setFillColor(p->save->buttons[i]->shape,
        p->btn_colors[p->save->buttons[i]->state + 3]);
}

static void handle_buttons(my_paint *p)
{
    for (int i = 0; i < p->save->buttons_nb; i++) {
        update_button_state(p->save->window, p->save->buttons[i]);
        if (IS_CLICK(p->save->buttons[i]->state))
            p->save->buttons[i]->function(p);
        for (int j = 0; j < 3; j++)
            sfText_setString(p->save->buttons[j]->text, "");
        sfText_setString(p->save->buttons[p->values->file_ext]->text, "X");
        update_buttons_color(i, p);
        if (IS_CLICK(p->save->buttons[i]->state))
            p->save->buttons[i]->state = NONE;
        sfRenderWindow_drawRectangleShape(p->save->window->renderer,
        p->save->buttons[i]->shape, NULL);
        sfRenderWindow_drawText(p->save->window->renderer,
        p->save->buttons[i]->text, NULL);
    }
}

static void events_loop(my_paint *p)
{
    sfEvent event = {0};

    while (sfRenderWindow_pollEvent(p->save->window->renderer, &event)) {
        if (event.type == sfEvtClosed || p->values->popup_shown == NO) {
            p->values->popup_shown = NO;
            destroy_window(p->save->window);
            break;
        }
        if (event.type == sfEvtResized)
            update_sizes(p->save);
    }
}

void handle_save_popup(my_paint *p)
{
    sfInt64 c_time = 0;

    if (p->values->popup_shown == SAVE_FILE) {
        sfRenderWindow_clear(p->save->window->renderer, p->bg_color);
        c_time = sfClock_getElapsedTime(p->save->window->clock).microseconds;
        if (c_time >= 1 / 60) {
            sfClock_restart(p->save->window->clock);
            p->save->timer++;
        }
        handle_field(p);
        handle_buttons(p);
        events_loop(p);
        sfRenderWindow_drawRectangleShape(p->save->window->renderer,
        p->save->field_bg, NULL);
        sfRenderWindow_drawText(p->save->window->renderer, p->save->field,
        NULL);
        sfRenderWindow_display(p->save->window->renderer);
    }
}
