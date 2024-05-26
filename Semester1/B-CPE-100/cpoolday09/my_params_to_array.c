/*
** EPITECH PROJECT, 2022
** CPOOL_Day09
** File description:
** my_params_to_array.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "./include/my.h"

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param param;
    struct info_param *test;

    test = malloc(sizeof(char) * (ac));
    for (int i = 0; i < ac; i++) {
        param.length = my_strlen(av[i]);
        param.str = av[i];
        param.copy = av[i];
        param.word_array = my_str_to_word_array(av[i]);
        test[i] = param;
    }
    return test;
}
