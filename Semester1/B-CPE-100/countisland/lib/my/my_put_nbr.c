/*
** EPITECH PROJECT, 2022
** CPOOL_Day04
** File description:
** my_put_nbr.c
*/

#include <stdio.h>

void my_putchar(char c);

int count_int_len(int nb)
{
    int len;

    len = 0;
    nb = (nb >= 0) ? nb : (nb * -1);
    while (nb > 0) {
        len++;
        nb /= 10;
    }
    return len;
}

int my_put_nbr(int nb)
{
    int LEN = count_int_len(nb);
    int temp[LEN];

    if (nb == 0)
        my_putchar('0');
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    for (int i = 0; i < LEN; i++) {
        temp[i] = nb % 10;
        nb /= 10;
    }
    for (int i = LEN - 1; i >= 0; i--) {
        my_putchar(temp[i] + '0');
    }
    return 0;
}
