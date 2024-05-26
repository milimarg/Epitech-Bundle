/*
** EPITECH PROJECT, 2022
** CPOOL_CWorkshopLib
** File description:
** my_put_nbr.c
*/

#include <unistd.h>

int my_intlen(int nb)
{
    nb = (nb < 0) ? nb * (-1) : nb;
    if (nb >= 0 && nb <= 9)
        return 1;
    if (nb >= -2147483647 && nb <= 2147483647)
        return my_intlen(nb / 10) + 1;
    else
        return 0;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    int LEN = my_intlen(nb);
    int temp[LEN];

    if (nb == 0) {
        write(1, "0", 1);
        return (0);
    }
    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    for (int i = 0; i < LEN; i++) {
        temp[i] = nb % 10;
        nb /= 10;
    }
    for (int i = LEN - 1; i >= 0; i--)
        my_putchar(temp[i] + '0');
    return (0);
}
