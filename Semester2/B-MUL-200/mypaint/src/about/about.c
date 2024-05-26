/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** about
*/

#include <stdlib.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/my.h"
#include "../../include/about.h"
#include "../../my_csfml/lib/lib.h"

static int events_about_loop(my_paint *p)
{
    sfEvent event = {0};

    while (sfRenderWindow_pollEvent(p->about->win->renderer, &event)) {
        if (event.type == sfEvtClosed) {
            p->values->popup_shown = NO;
            sfText_destroy(p->about->text);
            sfText_destroy(p->about->creator);
            free(p->about->log_name);
            destroy_window(p->about->win);
            return (1);
        }
    }
    return (0);
}

int handle_about_popup(my_paint *p)
{
    if (p->values->popup_shown == ABOUT) {
        sfRenderWindow_clear(p->about->win->renderer, sfWhite);
        if (events_about_loop(p))
            return (1);
        sfRenderWindow_drawText(p->about->win->renderer, p->about->text, NULL);
        sfRenderWindow_drawText(p->about->win->renderer, p->about->creator,
        NULL);
        sfRenderWindow_display(p->about->win->renderer);
    }
    return (0);
}

static void set_text(my_paint *p, char *str)
{
    p->about->text = sfText_create();
    p->about->creator = sfText_create();
    sfText_setPosition(p->about->text, p->about->text_pos);
    sfText_setString(p->about->text, p->about->log_name);
    sfText_setColor(p->about->text, sfBlack);
    sfText_setCharacterSize(p->about->text, 25);
    sfText_setFont(p->about->text, p->font);
    sfText_setPosition(p->about->creator, p->about->creator_pos);
    sfText_setString(p->about->creator, str);
    sfText_setColor(p->about->creator, sfBlack);
    sfText_setCharacterSize(p->about->creator, 20);
    sfText_setFont(p->about->creator, p->font);
}

void about(void *values)
{
    my_paint *p = values;
    char *str = "MyPaint is a software created by Florent GUITRE and\n"
    "Annita RASOANAIVO at EPITECH Strasbourg in 2023\nin 3 weeks."
    " It allows you to draw, to open and save\na file and"
    " you can change the colors and the shape\nof the pencil and"
    " eraser.\n\n\n"
    "Version : 1.0";

    if (p->values->popup_shown == NO) {
        p->values->popup_shown = ABOUT;
        take_logname(p);
        set_text(p, str);
        p->about->win = create_window("Help", p->about->size.x,
        p->about->size.y);
    }
}
