/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** main_handlers.c
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include "../my_csfml/window/window.h"
#include "../my_csfml/button/button.h"
#include "../include/structs.h"
#include "../include/my.h"
#include "../include/savefile.h"
#include "../include/openfile.h"
#include "../include/sidemenu.h"
#include "../include/about.h"
#include "../include/help.h"
#include "../include/draw.h"

int os_handler(my_window *window, sfEvent *event, my_paint *p)
{
    sfRenderWindow_clear(window->renderer, sfBlue);
    while (sfRenderWindow_pollEvent(window->renderer, event)) {
        if (event->type == sfEvtResized)
            update_window_ratio(window);
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window->renderer);
    }
    sfRenderWindow_drawSprite(window->renderer, p->os_bg_sprite, NULL);
    update_button_state(window, p->desktop_button[0]);
    if (IS_CLICK(p->desktop_button[0]->state))
        p->is_paint_open = 1;
    sfRenderWindow_display(window->renderer);
    return (0);
}

static void update_dropdown_animation(my_paint *p, int i)
{
    p->dp[i]->timer++;
    if (p->dp[i]->timer >= 6) {
        p->dp[i]->timer = 0;
        if (p->dp[i]->display_child && p->dp[i]->btn_idx < p->dp[i]->buttons_nb)
            p->dp[i]->btn_idx++;
        if (!p->dp[i]->display_child && p->dp[i]->btn_idx > 0)
            p->dp[i]->btn_idx--;
    }
}

int events_loop(my_window *window, sfEvent *event, my_paint *p)
{
    int is_first_boot = 0;

    if (sfClock_getElapsedTime(window->clock).microseconds > 1 / 60) {
        sfClock_restart(window->clock);
        for (int i = 0; p->dp[i] != NULL; i++)
            update_dropdown_animation(p, i);
    }
    while (sfRenderWindow_pollEvent(window->renderer, event)) {
        if (is_quit(event, p, window)) {
            is_first_boot = 1;
            break;
        }
        if (event->type == sfEvtResized)
            update_sizes_main(p);
    }
    return (is_first_boot);
}

static int display_elements(my_window *window, my_paint *p)
{
    display_logo(p, window);
    if (sfMouse_isButtonPressed(sfMouseLeft) && p->values->popup_shown == NO) {
        draw_function(window, p);
        array_color(p, window);
    }
    if (!sfMouse_isButtonPressed(sfMouseLeft) && p->values->popup_shown == NO) {
        p->pix->last = (sfVector2f){0, 0};
        p->pix->current = (sfVector2f){0, 0};
    }
    for (int i = 0; p->dp[i] != NULL; i++) {
        display_dropdown(p->dp[i], window);
        dropdown_handler(p->dp[i], window, p);
    }
    handle_slider(p, window);
    display_array_color(p, window);
    display_cursor(p);
    handle_save_popup(p);
    handle_about_popup(p);
    handle_help_popup(p);
    return (handle_open_popup(p));
}

void paint_handler(my_window *window, sfEvent *event, my_paint *p)
{
    static int is_first_boot = 1;

    is_first_boot = init_first_boot(is_first_boot, p, window);
    sfRenderWindow_clear(window->renderer, p->bg_color);
    check_keyboard_shortcuts(p);
    if (display_elements(window, p))
        return;
    is_first_boot = events_loop(window, event, p);
    sfRenderWindow_display(window->renderer);
}
