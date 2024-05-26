/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** file_explorer_utils.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../my_csfml/lib/lib.h"
#include "../../include/structs.h"
#include "../../include/openfile.h"
#include "../../include/my.h"

void add_directory_to_path(open_popup *o, char *current_path)
{
    path *dir = malloc(sizeof(path));
    path *temp = NULL;

    dir->dir_name = current_path;
    dir->len = my_strlen(dir->dir_name);
    dir->next = NULL;
    if (o->filepath_list == NULL)
        o->filepath_list = dir;
    else {
        temp = o->filepath_list;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = dir;
    }
}

int file_explorer_file_filter(struct dirent *pdirent)
{
    return (pdirent != NULL && ((pdirent->d_type == DT_DIR &&
    pdirent->d_name[0] != '.') || !check_ext(pdirent->d_name) ||
    !my_strcmp(pdirent->d_name, "..")));
}

static void register_infos(open_popup *o, int *i, sfIntRect **rect,
sfFont *font)
{
    sfText_setCharacterSize(o->buttons[*i]->text, 18);
    sfText_setFont(o->buttons[(*i)++]->text, font);
    (*rect)->top += (*rect)->height;
}

int get_files_infos(open_popup *o, sfFont *font, int register_buttons,
sfIntRect *rect)
{
    struct dirent *pdirent = NULL;
    int i = 0;

    do {
        pdirent = readdir(o->pdir);
        if (file_explorer_file_filter(pdirent) && register_buttons) {
            o->buttons[i] = add_button(rect, &sfBlack, &dummy, pdirent->d_name);
            register_infos(o, &i, &rect, font);
        }
        i += (file_explorer_file_filter(pdirent) && !register_buttons);
    } while (pdirent != NULL);
    if (!register_buttons) {
        closedir(o->pdir);
        o->pdir = opendir(o->current_path);
    }
    return ((register_buttons) ? 0 : i);
}
