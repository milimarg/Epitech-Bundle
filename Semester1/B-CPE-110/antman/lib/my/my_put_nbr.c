/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** put number
*/

#include "my.h"

int my_put_nbr_len_next(int nb, int *lenght)
{
    int i = 0, temp = nb, result;
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        *lenght = *lenght + 1;
    } if (nb > 0) {
        if (nb >= 10) {
            i = nb % 10;
            nb = nb / 10;
            *lenght = *lenght + 1;
            my_put_nbr_len_next(nb, lenght);
            my_putchar(48 + i);
        } else {
            *lenght = *lenght + 1;
            my_putchar(48 + (nb % 10));
        }
    } if (nb == 0) {
        my_putchar('0');
        *lenght = *lenght + 1;
    } return (*lenght);
}

int my_put_nbr_len(int nb)
{
    int length = 0;
    int result = my_put_nbr_len_next(nb, &length);
    return (result);
}
