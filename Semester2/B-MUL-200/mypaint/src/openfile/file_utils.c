/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** file_utils.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../my_csfml/lib/lib.h"
#include "../../include/structs.h"
#include "../../include/openfile.h"

void get_full_filepath(my_paint *p, char *element)
{
    path *fp = NULL;
    int full_len = 0;

    for (fp = p->open->filepath_list; fp != NULL; fp = fp->next)
        full_len += fp->len + 1;
    full_len += my_strlen(element);
    p->open->current_path = malloc(sizeof(char) * (full_len + 1));
    p->open->current_path[0] = 0;
    for (fp = p->open->filepath_list; fp != NULL; fp = fp->next) {
        p->open->current_path = my_strcat(p->open->current_path, fp->dir_name);
        p->open->current_path = my_strcat(p->open->current_path, "/");
    }
    p->open->current_path = my_strcat(p->open->current_path, element);
}

int check_file_is_valid(my_paint *p)
{
    struct stat st = {0};

    if (!stat(p->open->current_path, &st) && S_ISREG(st.st_mode) &&
        !check_ext(p->open->current_path)) {
        if (open_image(p->open->current_path, p->d)) {
            free(p->open->current_path);
            return (0);
        }
        free(p->open->current_path);
        p->values->popup_shown = NO;
        return (0);
    }
    return (1);
}
