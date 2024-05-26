/*
** EPITECH PROJECT, 2023
** str_count_words.c
** File description:
** counts words int str
*/

#include "../../include/my.h"

int str_count_words_checker(int *startword, char *str, int *i, int *a)
{
    if (*startword && my_is_alpha_num(str[*i])) {
        *a += my_is_alpha_num(str[*i]);
        *startword = 0;
    } else if (!(my_is_alpha_num(str[*i]))) {
        *startword = 1;
    }
}

int str_count_words(char const *str)
{
    int i = 0;
    int a = 0;
    int startword = 1;

    for (; str[i]; i++)
        str_count_words_checker(&startword, str, &i, &a);
    return (a);
}
