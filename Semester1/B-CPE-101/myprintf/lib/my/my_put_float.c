/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** my_put_nbr.c
*/

#include "../../include/funcs_struct_proto.h"

void display_float(int temp_size, int tata[], int whole_len, int isneg)
{
    int z = 0;
    int isdot = 0;

    if (isneg == -1)
        my_putchar('-');
    while (z < temp_size) {
        if (z == whole_len && !isdot) {
            my_putchar('.');
            isdot = 1;
        } else
            my_put_nbr(tata[z++]);
    }
}

int setting_up_whole(int whole, int whole_len, int tata[], int isneg)
{
    int shift_power = my_compute_power_rec(10, whole_len);
    int len = 0;

    if (isneg == -1)
        len++;
    for (int z = 0; z < whole_len; z++) {
        tata[whole_len - z - 1] = (whole % 10);
        whole /= 10;
    }
    return len;
}

int rounding_up(int temp_size, int tata[], int max_decimal, int len)
{
    int hallo = 1;

    if (tata[temp_size] >= 5)
        tata[temp_size - 1]++;
    while (tata[temp_size - hallo] > 9) {
        tata[temp_size - hallo] = 0;
        if (hallo < temp_size)
            tata[temp_size - (hallo + 1)]++;
        else {
            my_putchar('1');
            len++;
        }
        hallo++;
    }
    return len;
}

int anti_overflow(int max_decimal, long long max_value, int isdisplaying)
{
    if ((max_value <= -10000000000000000
    || max_value >= 10000000000000000) && isdisplaying) {
        my_putchar('0');
        my_putchar('.');
        for (int i = 0; i < max_decimal; i++)
            my_putchar('0');
        return (84);
    }
    return (0);
}

int my_put_float(double nb, int max_decimal, int isdisplaying)
{
    int isneg = ((int)nb < 0) ? - 1 : 1;
    int whole = (int)nb * isneg;
    int whole_len = my_intlen(whole);
    int temp_size = whole_len + max_decimal;
    int tata[temp_size + 1];
    long long temp = 0;
    int shift = 10;
    int extra_info = 0;

    extra_info = setting_up_whole(whole, whole_len, tata, isneg);
    for (int i = whole_len; i <= temp_size; shift *= 10) {
        temp = ((long long)(nb * shift));
        tata[i++] = ((temp % 10) * isneg);
        if (anti_overflow(max_decimal, temp, isdisplaying) == 84)
            return (84);
    }
    extra_info = rounding_up(temp_size, tata, max_decimal, extra_info);
    if (isdisplaying)
        display_float(temp_size, tata, whole_len, isneg);
    return (temp_size + extra_info + 1);
}
