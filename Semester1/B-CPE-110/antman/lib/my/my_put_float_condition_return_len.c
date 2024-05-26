/*
** EPITECH PROJECT, 2022
** my_put_float
** File description:
** my_put_float
*/
#include "my.h"
#include <stdio.h>

static void zero_before_maybe(int int_nb, int condition, int * length)
{
    int a = 1;
    long long power_condi = my_compute_power_rec(10, condition);
    if (int_nb != 0) {
        while (int_nb < 10 * condition) {
            int_nb = int_nb * 10;
        }
    } if (int_nb != 0) {
        while (int_nb < (power_condi / 10)) {
            *length = *length + 1;
            int_nb = int_nb * 10;
        }
    }
}

static int zero_condition(int int_nb, int condition, int * length)
{
    int a = 1;
    int power_condi = my_compute_power_rec(10, condition);
    if (int_nb != 0) {
        while (int_nb < 10 * condition) {
            *length = *length + 1;
            int_nb = int_nb * 10;
        } return (0);
    } else {
        while (a < condition) {
            *length = *length + 1;
            a++;
        }
    }
}

static double negative_condition(double nb, int * length, int condition)
{
    if (nb < 0) {
        nb = -nb;
        *length = *length + 1;
        return (nb);
    } return (nb);
}

int my_put_float_condition_len(double nb, int condition)
{
    int i = 0, int_nb = 0, length = 0;
    unsigned long long arron = 0, ten = 1;
    int a = 0;
    nb = negative_condition(nb, &length, condition);
    for (i; (nb - i) > 1; i++);
    nb = nb - i;
    while (a < condition) {
        ten = ten * 10;
        a++;
    } arron = nb * ten;
    length = length + len_nbr(i);
    if (condition <= 0)
        return (length);
    length = length + 1;
    zero_before_maybe(arron, condition, &length);
    zero_condition(arron, condition, &length);
    length = length + len_nbr(arron);
    if (condition == 1 || condition == 2)
        length = length - 1;
    return (length);
}
