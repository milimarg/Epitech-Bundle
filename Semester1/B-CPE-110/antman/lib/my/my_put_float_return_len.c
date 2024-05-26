/*
** EPITECH PROJECT, 2022
** my_put_float
** File description:
** my_put_float
*/
#include "my.h"
#include <stdio.h>

static int zero(int int_nb)
{
    if (int_nb < 10) {
        return (5);
    } if (int_nb < 100) {
        return (4);
    } if (int_nb < 1000) {
        return (3);
    } if (int_nb < 10000) {
        return (2);
    } if (int_nb < 100000) {
        return (1);
    }
    return (0);
}

static double negative(double nb, int * length)
{
    if (nb < 0) {
        nb = -nb;
        ++*length;
        return (nb);
    } return (nb);
}

int my_put_float_len(double nb)
{
    int i = 0, int_nb = 0, length = 0;
    unsigned long long arron = 0;
    nb = negative(nb, &length);
    for (i; (nb - i) > 1; i++);
    nb = nb - i;
    arron = nb * 1000000;
    int_nb = arron;
    if (arron == 1000000) {
        i++;
        length = length + len_nbr(i);
    } else
        length = length + len_nbr(i);
    length = length + 1;
    length = length + zero(int_nb);
    if (int_nb != 1000000)
        length = length + len_nbr(int_nb);
    else {
        length = length + 6;
    } return (length);
}
