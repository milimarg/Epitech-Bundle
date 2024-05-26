/*
** EPITECH PROJECT, 2022
** CPOOL_mini_printf
** File description:
** lib.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

int my_intlen(int nb)
{
    nb = (nb < 0) ? (nb * (-1)) : nb;
    if (nb >= 0 && nb <= 9)
        return 1;
    if (nb >= -2147483647 && nb <= 2147483647)
        return my_intlen(nb / 10) + 1;
    else
        return 0;
}

int my_put_nbr(int nb)
{
    int LEN = my_intlen(nb);
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
