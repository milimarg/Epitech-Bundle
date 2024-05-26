/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** add_dropdowns_buttons.c
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include "../my_csfml/button/button.h"
#include "../include/structs.h"
#include "../include/savefile.h"
#include "../include/openfile.h"
#include "../include/my.h"
#include "../include/about.h"
#include "../include/help.h"

my_dropdown *add_dropdown_file(my_paint *p, sfColor *none_state)
{
    my_dropdown *dp = NULL;
    int j = 0;
    sfIntRect dp_pos = {0, 0, 110, 40};
    sfIntRect btn_pos = {0, 40, 110, 30};
    char *btn_titles[] = {"New file", "Open file", "Save file"};
    void (*func[])(void *) = {&new_file, &open_file, &save_file};

    dp = init_dropdown(&dp_pos, none_state, "File");
    dp->buttons_nb = 3;
    sfText_setFont(dp->text, p->font);
    dp->buttons = init_buttons_array(dp->buttons_nb);
    for (j = 0; j < dp->buttons_nb; j++) {
        dp->buttons[j] = add_button(&btn_pos, &sfRed, func[j], btn_titles[j]);
        sfText_setFont(dp->buttons[j]->text, p->font);
        btn_pos.top += btn_pos.height;
    }
    dp->buttons[j] = NULL;
    return (dp);
}

my_dropdown *add_dropdown_edit(my_paint *p, sfColor *none_state)
{
    my_dropdown *dp = NULL;
    int j = 0;
    sfIntRect dp_pos = {110, 0, 110, 40};
    sfIntRect btn_pos = {110, 40, 110, 30};
    char *btn_titles[] = {"Pencil", "Eraser"};
    void (*func[])(void *) = {&set_pencil, &set_eraser};

    dp = init_dropdown(&dp_pos, none_state, "Edit");
    dp->buttons_nb = 2;
    sfText_setFont(dp->text, p->font);
    dp->buttons = init_buttons_array(dp->buttons_nb);
    for (j = 0; j < dp->buttons_nb; j++) {
        dp->buttons[j] = add_button(&btn_pos, &sfRed, func[j], btn_titles[j]);
        sfText_setFont(dp->buttons[j]->text, p->font);
        btn_pos.top += btn_pos.height;
    }
    dp->buttons[j] = NULL;
    return (dp);
}

my_dropdown *add_dropdown_help(my_paint *p, sfColor *none_state)
{
    my_dropdown *dp = NULL;
    int j = 0;
    sfIntRect dp_pos = {220, 0, 110, 40};
    sfIntRect btn_pos = {220, 40, 110, 30};
    char *btn_titles[] = {"About", "Help"};
    void (*func[])(void *) = {&about, &help};

    dp = init_dropdown(&dp_pos, none_state, "Help");
    dp->buttons_nb = 2;
    sfText_setFont(dp->text, p->font);
    dp->buttons = init_buttons_array(dp->buttons_nb);
    for (j = 0; j < dp->buttons_nb; j++) {
        dp->buttons[j] = add_button(&btn_pos, &sfRed, func[j], btn_titles[j]);
        sfText_setFont(dp->buttons[j]->text, p->font);
        btn_pos.top += btn_pos.height;
    }
    dp->buttons[j] = NULL;
    return (dp);
}

void fill_dropdowns(my_paint *p)
{
    sfColor none_state = {169, 169, 169, 255};

    p->dp_number = 3;
    p->dp = malloc(sizeof(my_dropdown *) * (p->dp_number + 1));
    p->dp[0] = add_dropdown_file(p, &none_state);
    p->dp[1] = add_dropdown_edit(p, &none_state);
    p->dp[2] = add_dropdown_help(p, &none_state);
    p->dp[p->dp_number] = NULL;
    for (int i = 0; i < p->dp_number; i++) {
        p->dp[i]->timer = 0;
        p->dp[i]->btn_idx = 0;
    }
}

void dropdown_handler(my_dropdown *dp, my_window *window, my_paint *p)
{
    update_dropdown_state(window, dp, p->values);
    for (int i = 0; i < dp->btn_idx; i++) {
        sfRectangleShape_setFillColor(dp->buttons[i]->shape,
        p->btn_colors[dp->buttons[i]->state]);
    }
    detect_clicks_dropdown(dp, window, p->values, p);
    for (int i = 0; i < dp->btn_idx; i++) {
        sfRenderWindow_drawRectangleShape(window->renderer,
        dp->buttons[i]->shape, NULL);
        sfRenderWindow_drawText(window->renderer,
        dp->buttons[i]->text, NULL);
    }
}
