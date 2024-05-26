/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** game_utils.c
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../my_csfml/button/button.h"
#include "../include/structs.h"
#include "../include/my.h"
#include "../include/savefile.h"
#include "../include/openfile.h"
#include "../include/sidemenu.h"
#include "../include/about.h"
#include "../include/help.h"
#include "../include/draw.h"

void paint_destroyer(my_paint *p)
{
    for (int i = 0; i < p->dp_number; i++) {
        destroy_buttons_array(p->dp[i]->buttons);
        destroy_dropdown(p->dp[i]);
    }
    free(p->dp);
    sfFont_destroy(p->font);
    destroy_drawing_area(p->d);
    free(p->btn_colors);
    free(p->pix);
    destroy_savefile_popup(p->save);
    destroy_openfile_popup(p->open);
    destroy_arr_color(p->arr_color);
    destroy_menu(p->m);
    free(p->about);
    free(p->help);
}

static void init_colors_enum_paint(my_paint *p)
{
    p->bg_color = (sfColor){71, 71, 71, 255};
    p->btn_colors = malloc(sizeof(sfColor) * 6);
    p->btn_colors[0] = (sfColor){169, 169, 169, 255};
    p->btn_colors[1] = (sfColor){128, 128, 128, 255};
    p->btn_colors[2] = (sfColor){105, 105, 105, 255};
    p->btn_colors[3] = (sfColor){72, 167, 11, 255};
    p->btn_colors[4] = (sfColor){37, 111, 21, 255};
    p->btn_colors[5] = (sfColor){16, 86, 31, 255};
    p->values->popup_shown = NO;
    p->values->file_ext = JPG;
}

static void init_popup(my_paint *p)
{
    add_save_file_popup(p);
    add_open_file_popup(p);
    p->about = malloc(sizeof(about_popup));
    add_about_popup(p);
    p->help = malloc(sizeof(help_popup));
    add_help_popup(p);
}

int init_first_boot(int is_first_boot, my_paint *p, my_window *window)
{
    if (is_first_boot) {
        is_first_boot = 0;
        p->font = sfFont_createFromFile("./assets/Roboto-Regular.ttf");
        fill_dropdowns(p);
        p->d = malloc(sizeof(drawing_area_t));
        init_pixel_area(p->d, p->values, p->w);
        p->pix = malloc(sizeof(pixels_t));
        init_pixels(p->pix);
        init_colors_enum_paint(p);
        init_popup(p);
        p->arr_color = init_arr_col(p->arr_color);
        p->m = malloc(sizeof(side_menu_t));
        update_window_ratio(window);
        init_side_menu(p);
        create_cursor(p->d, p->m);
        set_slider_value(p);
        if (p->enable_os)
            update_sizes_main(p);
    }
    return (is_first_boot);
}

int is_quit(sfEvent *event, my_paint *p, my_window *window)
{
    if (event->type == sfEvtClosed) {
        p->is_paint_open = 0;
        paint_destroyer(p);
        if (!p->enable_os)
            sfRenderWindow_close(window->renderer);
        return (1);
    }
    return (0);
}
