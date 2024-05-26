/*
** EPITECH PROJECT, 2023
** my_csfml_container
** File description:
** dropdown_utils.c
*/

#include <SFML/Graphics.h>
#include "../window/window.h"
#include "button.h"

void update_dropdown_state(my_window *window, my_dropdown *dp)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(dp->shape);
    sfVector2i pos = sfMouse_getPositionRenderWindow(window->renderer);
    int hover_status = 0;
    int click_status = sfMouse_isButtonPressed(sfMouseLeft);

    pos.x *= window->ratio.x;
    pos.y *= window->ratio.y;
    hover_status = sfFloatRect_contains(&rect, pos.x, pos.y);
    if (!hover_status && !click_status)
        dp->state = NONE;
    if (hover_status && !click_status)
        dp->state = HOVER;
    if (hover_status && click_status)
        dp->state = CLICKED;
}

void detect_clicks_dropdown(my_dropdown *dp, my_window *window,
my_values *values, void *dummy_paint)
{
    int hover_dp_child = 0;

    update_dropdown_state(window, dp);
    for (int i = 0; dp->buttons[i] != NULL; i++) {
        update_button_state(window, dp->buttons[i]);
        if (IS_HOVER(dp->buttons[i]->state) || IS_CLICK(dp->buttons[i]->state))
            hover_dp_child = 1;
        if (IS_CLICK(dp->buttons[i]->state) && !dp->buttons[i]->is_clicked &&
        dp->display_child) {
            dp->buttons[i]->is_clicked = 1;
            dp->buttons[i]->function(dummy_paint);
        }
        if (!IS_CLICK(dp->buttons[i]->state) && dp->buttons[i]->is_clicked)
            dp->buttons[i]->is_clicked = 0;
    }
    dp->display_child = (IS_HOVER(dp->state) || IS_CLICK((dp->state))) ? 1 :
    dp->display_child;
    dp->display_child = (dp->display_child && !hover_dp_child &&
    (!IS_HOVER(dp->state))) ? 0 : dp->display_child;
}
