/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** display.c
*/

#include "../include/my.h"
#include "../include/my_struct.h"

void display_newlines(path_helper_t *pathinfos, int *args_indexes, int q)
{
    if (pathinfos->path_nb == 1) {
        if (args_indexes[1] || args_indexes[6])
            my_putstr("");
        else
            my_putstr("\n");
    } else {
        if ((args_indexes[1] || args_indexes[6]) &&
        q < (pathinfos->path_nb - 1) && !args_indexes[3])
            my_putstr("\n");
        if ((!(args_indexes[1] || args_indexes[6]) &&
        q < (pathinfos->path_nb - 1)) && !args_indexes[3])
            my_putstr("\n\n");
        if (args_indexes[3] && !(args_indexes[1] || args_indexes[6]))
            my_putchar(' ');
    }
}

void display_path_header(path_helper_t *pathinfos, int q, int *args_indexes)
{
    if (pathinfos->path_nb > 1 && !args_indexes[3]) {
        my_putstr(pathinfos->path_array[q]);
        my_putstr(":\n");
    }
}
