/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** returns nb in str
*/

#include "../../include/my.h"

int my_getnbr_checker(char *str, int *i, int *nb, int *n)
{
    int fn = 0;

    if (str[*i] == '-') {
        fn = (fn % 2 + 1) % 2;
    } else if (47 < str[*i] && str[*i] < 58) {
        *n = 10 * (*n + str[*i] - '0');
        (*nb)++;
    }
    (*i)++;
    return (fn);
}

int my_getnbr(char const *str)
{
    long long n = 0;
    int i = 0;
    int nb = 0;
    int fn = 0;

    while ((str[i]) && (nb < 11) && (!(nb) || (47 < str[i] && str[i] < 58)))
        fn = my_getnbr_checker(str, &i, &nb, &n);
    return (my_is_int(n, fn, nb));
}
