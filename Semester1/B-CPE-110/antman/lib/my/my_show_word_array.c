/*
** EPITECH PROJECT, 2022
** my_show_word_array
** File description:
** good prog
*/

#include "my.h"

int my_show_word_array(char * const *tab)
{
    int i = 0;
    while (tab[i] != 0) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
}
