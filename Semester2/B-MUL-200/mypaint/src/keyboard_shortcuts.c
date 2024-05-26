/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** keyboard_shortcuts.c
*/

#include <SFML/Graphics.h>
#include "../my_csfml/window/window.h"
#include "../my_csfml/button/button.h"
#include "../include/structs.h"
#include "../include/my.h"
#include "../include/openfile.h"
#include "../include/savefile.h"
#include "../include/help.h"

void check_keyboard_shortcuts(my_paint *p)
{
    int shortcuts_nb = 4;
    int keys[] = {sfKeyN, sfKeyO, sfKeyS, sfKeyS, sfKeyH};
    void (*func[])(void *) = {&new_file, &open_file, &save_file, &help};

    for (int i = 0; i < shortcuts_nb; i++) {
        if (sfKeyboard_isKeyPressed(sfKeyLControl) &&
        sfKeyboard_isKeyPressed(keys[i]))
            func[i](p);
    }
}
