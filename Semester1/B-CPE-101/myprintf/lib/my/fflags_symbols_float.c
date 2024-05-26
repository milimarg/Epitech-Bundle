/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** fflags_flags.c
*/

#include "../../include/funcs_struct_proto.h"

int fflag_dash_float(int len, valuesbox_t flag_utils, double value,
int isdisplaying)
{
    return (len);
}

int fflag_plus_float(int len, valuesbox_t flag_utils, double value,
int isdisplaying)
{
    if (value > 0) {
        if (isdisplaying)
            my_putchar('+');
        len++;
    }
    return (len);
}

int fflag_space_float(int len, valuesbox_t flag_utils, double value,
int isdisplaying)
{
    if (isdisplaying && flag_utils.width == 0)
        my_putchar(' ');
    if (isdisplaying && flag_utils.flag == 'e' && flag_utils.width > 0)
        my_putchar(' ');
    return (++len);
}

int fflag_hashtag_float(int len, valuesbox_t flag_utils, double value,
int isdisplaying)
{
    return (len);
}

int fflag_zero_float(int len, valuesbox_t flag_utils, double value,
int isdisplaying)
{
    thefor(flag_utils.width, len, '0');
    return (flag_utils.width);
}
