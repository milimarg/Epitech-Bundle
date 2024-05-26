/*
** EPITECH PROJECT, 2022
** CPOOL_Day09
** File description:
** my_show_param_array.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "./include/my.h"

struct info_param *my_params_to_array(int ac, char **av);

int my_show_param_array(struct info_param const *par)
{
    int i;

    i = 0;
    while (par[i].str != 0) {
        my_putstr(par[i].copy);
        my_putchar('\n');
        my_put_nbr(par[i].length);
        my_putchar('\n');
        my_show_word_array(par[i].word_array);
        my_putchar('\n');
        i++;
    }
    return 0;
}
