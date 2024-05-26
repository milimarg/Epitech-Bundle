/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** help
*/

#include <stdlib.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/my.h"
#include "../../include/about.h"
#include "../../include/help.h"

static int events_help_loop(my_paint *p)
{
    sfEvent event = {0};

    while (sfRenderWindow_pollEvent(p->help->win->renderer, &event)) {
        if (event.type == sfEvtClosed) {
            p->values->popup_shown = NO;
            sfTexture_destroy(p->help->bg);
            sfSprite_destroy(p->help->sprite);
            destroy_window(p->help->win);
            return (1);
        }
    }
    return (0);
}

int handle_help_popup(my_paint *p)
{
    if (p->values->popup_shown == HELP) {
        sfRenderWindow_clear(p->help->win->renderer, sfWhite);
        if (events_help_loop(p))
            return (1);
        sfSprite_setTexture(p->help->sprite, p->help->bg, sfTrue);
        sfRenderWindow_drawSprite(p->help->win->renderer, p->help->sprite,
        NULL);
        sfRenderWindow_display(p->help->win->renderer);
    }
    return (0);
}

void help(void *values)
{
    my_paint *p = values;

    if (p->values->popup_shown == NO) {
        p->values->popup_shown = HELP;
        p->help->sprite = sfSprite_create();
        p->help->bg = sfTexture_createFromFile("./assets/help.png", NULL);
        p->help->win = create_window("Help", p->help->size.x, p->help->size.y);
    }
}
