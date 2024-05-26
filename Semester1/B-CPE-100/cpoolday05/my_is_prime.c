/*
** EPITECH PROJECT, 2022
** CPOOL_Day05
** File description:
** my_is_prime.c
*/

#include <stdio.h>

int my_is_prime(int nb)
{
    int a;
    int final;

    final = 1;
    for (int i = 2; i < nb; i++) {
        a = nb % i;
        if (a == 0) {
            final = 0;
            break;
        }
    }
    if (nb <= 1)
        final = 0;
    return final;
}
