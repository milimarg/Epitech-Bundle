/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** il est 22h
*/

void my_putchar(char c);

void my_put_unnbr(int long nb)
{
    int long x;
    if (nb < 0) {
        nb = -nb;
        x = 4294967295 - nb + 1;
        my_put_unnbr(x);
    } else {
        if (nb / 10) {
            my_put_unnbr(nb / 10);
        }
    my_putchar('0' + nb % 10);
    }
}
