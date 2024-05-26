/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** fflags_flags.c
*/

#include "../../include/funcs_struct_proto.h"

int fflag_dash_putnbr_base(int len, valuesbox_t flag_utils, long value,
int isdisplaying)
{
    return (len);
}

int fflag_plus_putnbr_base(int len, valuesbox_t flag_utils, long value,
int isdisplaying)
{
    if (value > 0 && flag_utils.flag == 'p') {
        if (isdisplaying)
            my_putchar('+');
        len++;
    }
    return (len);
}

int fflag_space_putnbr_base(int len, valuesbox_t flag_utils, long value,
int isdisplaying)
{
    if (isdisplaying && flag_utils.width == 0 && flag_utils.flag != 'o')
        my_putchar(' ');
    return (len);
}

int fflag_hashtag_putnbr_base(int len, valuesbox_t flag_utils, long value,
int isdisplaying)
{
    char flag = flag_utils.flag;
    if (flag != 'p') {
        if (isdisplaying)
            my_putchar('0');
        len++;
    }
    if (flag == 'x' || flag == 'X' || flag == 'b') {
        if (isdisplaying)
            my_putchar(flag);
        len++;
    }
    return (len);
}

int fflag_zero_putnbr_base(int len, valuesbox_t flag_utils, long value,
int isdisplaying)
{
    if (isdisplaying && flag_utils.flag == 'p') {
        my_putchar('0');
        my_putchar('x');
    }
    thefor(flag_utils.width, len, '0');
    return (flag_utils.width);
}
