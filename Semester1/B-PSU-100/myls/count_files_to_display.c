/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** count_files_to_display.c
*/

#include "./include/my.h"

int count_files_to_display(int *args_indexes, char *file_path[], int values[],
int highest_nbs[])
{
    char *file = file_path[0];
    char *path = file_path[1];
    int file_to_display = values[1];
    int file_nb = values[2];

    if (((file[0] == '.' && args_indexes[0]) || (file[0] != '.')) &&
    !args_indexes[3]) {
        if_not_flag_d(args_indexes, values, file_path, highest_nbs);
        values[0]++;
    }
    if (args_indexes[3]) {
        if_flag_d(args_indexes, path, file_nb, highest_nbs);
        return (-42);
    }
    return (values[0]);
}
