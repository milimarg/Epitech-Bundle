/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** buttons.c
*/

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../my_csfml/lib/lib.h"
#include "../../include/openfile.h"

int check_ext(char *filename)
{
    char *ext_names[] = {".jpg", ".bmp", ".png"};
    int ext_nb = 3;
    int filename_len = my_strlen(filename);
    char *ext = filename;

    if (filename_len < 5)
        return (1);
    if (filename[filename_len - 4] != '.')
        return (1);
    ext += filename_len - 4;
    for (int i = 0; i < ext_nb; i++)
        if (!my_strcmp(ext, ext_names[i]))
            return (0);
    return (1);
}

void open_file(void *values)
{
    my_paint *p = values;

    if (p->values->popup_shown == NO) {
        p->values->popup_shown = OPEN_FILE;
        p->open->current_path = "./";
        p->open->pdir = opendir(p->open->current_path);
        p->open->filepath_list = NULL;
        p->open->is_dir_clicked = 0;
        p->open->window = create_window("Open file", p->open->size.x,
        p->open->size.y);
        update_window_ratio(p->open->window);
        set_file_explorer(p->open, p->font);
    }
}
