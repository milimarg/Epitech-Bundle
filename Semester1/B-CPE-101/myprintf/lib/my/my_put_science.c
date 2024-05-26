/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** my_putnbr_base.c
*/

#include <stdio.h>

void my_putchar(char c);

int my_put_nbr(int nb);

int my_put_float(double nb, int max_decimal, int isdisplaying);

int my_intlen(int nb);

int display_put_science(double nb, int box[], int count, int len)
{
    int isdisplaying = len;

    len = 0;
    len += my_put_float(nb, box[2], isdisplaying);
    if (isdisplaying) {
        my_putchar(box[1]);
        my_putchar((box[0]) ? '-' : '+');
    }
    if (count >= 1 && count <= 9) {
        if (isdisplaying)
            my_putchar('0');
        len++;
    }
    if (isdisplaying)
        my_put_nbr(count);
    len += (2 + my_intlen(count));
    return (len);
}

int my_put_science(double nb, char exp_char, int isdisplaying, int max_decimal)
{
    int isneg = (nb < 0) ? -1 : 1;
    nb *= (isneg == -1) ? -1 : 1;
    int count = 0;
    int box[3] = {0, exp_char, max_decimal};
    double nb_edit = nb;

    if (nb < 1)
        while (nb_edit <= 1.0) {
            count++;
            nb_edit *= 10;
            box[0] = 1;
        }
    if (nb > 9)
        while (nb_edit >= 10.0) {
            count++;
            nb_edit /= 10;
        }
    if (isneg == -1 && isdisplaying)
        my_putchar('-');
    return (display_put_science(nb_edit, box, count, isdisplaying));
}
