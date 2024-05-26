/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** il est 22h
*/

void my_putchar(char c);

int my_rev_nbr(int long nb)
{
    int rev = 0;
    while (nb != 0) {
        rev = rev * 10 + (nb % 10);
        nb /= 10;
    }
    return rev;
}
