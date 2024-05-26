/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** get_args.c
*/

#include <stdlib.h>
#include "./include/my.h"

int check_save_args(char *arg, int *args_indexes, int args_nb,
char *allowed_args)
{
    int arg_len = my_strlen(arg);
    int o = 0;

    for (int j = 0; j < arg_len; j++) {
        for (int k = 0; k < args_nb; k++) {
            args_indexes[k] = (allowed_args[k] == arg[j])
            ? 1 : args_indexes[k];
            o = (allowed_args[k] == arg[j]) ? o + 1 : o;
        }
    }
    if (o == 0)
        return (84);
    return (0);
}

int get_args(char *argv[], int args_nb, char *allowed_args, int *args_indexes)
{
    int o = 0;

    for (int j = 0; j < args_nb; j++)
        args_indexes[j] = 0;
    for (int i = 0; argv[i]; i++)
        o = (argv[i][0] == '-') ?
        check_save_args(argv[i], args_indexes, args_nb, allowed_args) : o;
        if (o == 84)
            return (84);
}
