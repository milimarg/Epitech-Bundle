/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** save_popup.c
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/my.h"
#include "../../include/savefile.h"

static void add_ok_button(my_paint *p, void (*func[]))
{
    sfIntRect rect = {p->save->size.x / 2, p->save->size.y - 30, 30, 20};
    sfVector2f origin = {rect.width / 2, rect.height / 2};
    sfVector2f ok_pos = {rect.left + 3, rect.top - 1};

    p->save->buttons[3] = add_button(&rect, &p->btn_colors[3], func[3], "OK");
    sfRectangleShape_setOrigin(p->save->buttons[3]->shape, origin);
    sfText_setOrigin(p->save->buttons[3]->text, origin);
    sfText_setFont(p->save->buttons[3]->text, p->font);
    sfText_setColor(p->save->buttons[3]->text, sfBlack);
    sfText_setCharacterSize(p->save->buttons[3]->text, 18);
    sfText_setPosition(p->save->buttons[3]->text, ok_pos);
}

static void add_choice_buttons(my_paint *p, void *func[], int offset,
char *ext_names[])
{
    sfIntRect r = {0};
    sfVector2f o = {0};

    for (int i = 0; i < p->save->ext_nb; i++) {
        r = (sfIntRect){(p->save->size.x / 2 + (offset * (i - 1))),
        p->save->size.y / 2, 20, 20};
        o = (sfVector2f){r.width / 2, r.height / 2};
        p->save->buttons[i] = add_button(&r, &p->btn_colors[0], func[i], "X");
        sfRectangleShape_setOrigin(p->save->buttons[i]->shape, o);
        sfText_setFont(p->save->buttons[i]->text, p->font);
        sfText_setCharacterSize(p->save->buttons[i]->text, 17);
        sfText_setOrigin(p->save->buttons[i]->text, o);
        p->save->ext_names[i] = sfText_create();
        sfText_setFont(p->save->ext_names[i], p->font);
        sfText_setCharacterSize(p->save->ext_names[i], 17);
        sfText_setString(p->save->ext_names[i], ext_names[i]);
        sfText_setOrigin(p->save->ext_names[i], o);
        o = (sfVector2f){r.left - 4, r.top + r.height + 5};
        sfText_setPosition(p->save->ext_names[i], o);
    }
}

static void set_field_design(my_paint *p, sfVector2f *pos, sfVector2f *size)
{
    p->save->field_bg_color = (sfColor){54, 54, 54, 255};
    p->save->field_bg = sfRectangleShape_create();
    *pos = (sfVector2f){pos->x - 5, 20};
    sfRectangleShape_setPosition(p->save->field_bg, *pos);
    sfRectangleShape_setOutlineColor(p->save->field_bg, sfBlue);
    sfRectangleShape_setOutlineThickness(p->save->field_bg, 0);
    sfRectangleShape_setFillColor(p->save->field_bg, p->save->field_bg_color);
    sfRectangleShape_setSize(p->save->field_bg, *size);
    sfRectangleShape_setOutlineThickness(p->save->field_bg, 1);
}

static void add_field(my_paint *p)
{
    sfVector2f size = {475, 40};
    sfVector2f pos = {(p->save->size.x - size.x) / 2, 20};

    p->save->field_size = 0;
    p->save->char_max = 20;
    p->save->field_content = malloc(sizeof(char) * (p->save->char_max + 1));
    for (int i = 0; i < p->save->char_max; i++)
        p->save->field_content[i] = 0;
    p->save->field_content[p->save->char_max] = 0;
    p->save->field = sfText_create();
    sfText_setPosition(p->save->field, pos);
    sfText_setString(p->save->field, p->save->field_content);
    sfText_setFont(p->save->field, p->font);
    set_field_design(p, &pos, &size);
    p->save->is_field_selected = 1;
}

void add_save_file_popup(my_paint *p)
{
    int offset = 100;
    void (*func[]) = {&set_jpg, &set_bmp, &set_png, &validate_filename_popup};
    char *ext_names[] = {"JPG", "BMP", "PNG"};

    p->save = malloc(sizeof(save_popup));
    p->save->size = (sfVector2f){600, 200};
    p->save->buttons_nb = 4;
    p->save->ext_nb = 3;
    p->save->buttons = init_buttons_array(p->save->buttons_nb);
    add_ok_button(p, func);
    p->save->ext_names = malloc(sizeof(sfText *) * p->save->ext_nb);
    add_choice_buttons(p, func, offset, ext_names);
    add_field(p);
    p->save->is_key_pressed = 0;
    p->save->cursor = '_';
    p->save->timer = 0;
    p->save->is_cursor_visible = 0;
}
