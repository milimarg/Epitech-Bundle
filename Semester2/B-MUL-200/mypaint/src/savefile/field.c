/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** savefile_popup_field.c
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"

static int manage_alpha(save_popup *s, int i)
{
    static int alpha_index = 97;

    if (sfKeyboard_isKeyPressed(sfKeyLShift) && alpha_index == 97)
        alpha_index = 65;
    if (!sfKeyboard_isKeyPressed(sfKeyLShift) && alpha_index == 65)
        alpha_index = 97;
    if (((i >= sfKeyA && i <= sfKeyZ) || i == sfKeyHyphen) &&
        sfKeyboard_isKeyPressed(i) && s->field_size < s->char_max) {
        if (!s->is_key_pressed) {
            s->is_key_pressed = 1;
            s->field_content[s->field_size] = (i == sfKeyHyphen)
            ? 45 : i + alpha_index;
            s->field_size++;
            s->field_content[s->field_size] = s->cursor;
            sfText_setString(s->field, s->field_content);
            return (1);
        } else
            return (1);
    }
    return (0);
}

static int manage_backspace(save_popup *s, int i)
{
    if (i == sfKeyBackspace && sfKeyboard_isKeyPressed(i) &&
        s->field_size > 0) {
        if (!s->is_key_pressed) {
            s->is_key_pressed = 1;
            s->field_content[s->field_size - 1] = s->cursor;
            s->field_content[s->field_size] = 0;
            s->field_size--;
            sfText_setString(s->field, s->field_content);
            return (1);
        } else
            return (1);
    }
    return (0);
}

static int check_key_pressing(my_paint *p)
{
    for (int i = 0; i < sfKeyCount; i++) {
        if (manage_alpha(p->save, i) || manage_backspace(p->save, i))
            return (1);
        if (((i >= sfKeyA && i <= sfKeyZ) || i == sfKeyHyphen) &&
            sfKeyboard_isKeyPressed(i) &&
            p->save->field_size == p->save->char_max)
            sfSound_play(p->os_sounds[2]);
        if (i == sfKeyBackspace && sfKeyboard_isKeyPressed(i) &&
            p->save->field_size == 0)
            sfSound_play(p->os_sounds[2]);
    }
    return (0);
}

static void manage_blinking_cursor(save_popup *s)
{
    if (!s->is_field_selected) {
        if (s->field_content[s->field_size] == '_') {
            s->field_content[s->field_size] = '\0';
            sfText_setString(s->field, s->field_content);
        }
        return;
    }
    if (s->timer >= 60) {
        s->timer = 0;
        s->is_cursor_visible = !s->is_cursor_visible;
        s->cursor = (s->is_cursor_visible) ? '_' : '\0';
        s->field_content[s->field_size] = s->cursor;
        sfText_setString(s->field, s->field_content);
    }
}

void handle_field(my_paint *p)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(p->save->field_bg);
    sfVector2i pos = sfMouse_getPositionRenderWindow(p->save->window->renderer);
    int click = sfMouse_isButtonPressed(sfMouseLeft);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) && click &&
    !p->save->is_field_selected) {
        p->save->is_field_selected = 1;
        sfRectangleShape_setOutlineThickness(p->save->field_bg, 1);
    }
    if (!sfFloatRect_contains(&rect, pos.x, pos.y) && click &&
    p->save->is_field_selected) {
        p->save->is_field_selected = 0;
        sfRectangleShape_setOutlineThickness(p->save->field_bg, 0);
    }
    manage_blinking_cursor(p->save);
    if (check_key_pressing(p))
        return;
    p->save->is_key_pressed = 0;
}
