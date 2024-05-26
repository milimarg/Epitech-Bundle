/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** save_popup_buttons.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../my_csfml/lib/lib.h"

void save_file(void *values)
{
    my_paint *p = values;

    if (p->values->popup_shown == NO) {
        p->values->popup_shown = SAVE_FILE;
        p->save->window = create_window("Save file", p->save->size.x,
        p->save->size.y);
    }
}

void set_jpg(void *values)
{
    my_paint *p = values;

    p->values->file_ext = JPG;
}

void set_bmp(void *values)
{
    my_paint *p = values;

    p->values->file_ext = BMP;
}

void set_png(void *values)
{
    my_paint *p = values;

    p->values->file_ext = PNG;
}

void validate_filename_popup(void *values)
{
    my_paint *p = values;
    char *ext_names[] = {".jpg", ".bmp", ".png"};
    char *result = NULL;
    int filename_len = 0;

    filename_len = (p->save->field_content[0] == '\0') ? 5 :
    my_strlen(p->save->field_content);
    result = malloc(sizeof(char) * (filename_len + 5));
    result[0] = 0;
    result[filename_len + 4] = 0;
    if (p->save->field_content[p->save->field_size] == '_')
        p->save->field_content[p->save->field_size] = '\0';
    result = (p->save->field_content[0] == '\0') ? my_strcat(result, "image") :
    my_strcat(result, p->save->field_content);
    result = my_strcat(result, ext_names[p->values->file_ext]);
    sfImage_saveToFile(p->d->area, result);
    free(result);
    p->values->popup_shown = NO;
}
