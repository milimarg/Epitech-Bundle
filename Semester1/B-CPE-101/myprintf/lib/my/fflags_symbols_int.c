/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** fflags_flags.c
*/

#include "../../include/funcs_struct_proto.h"

int fflag_dash_int(int len, valuesbox_t flag_utils, int value,
int isdisplaying)
{
    return (len);
}

int fflag_plus_int(int len, valuesbox_t flag_utils, int value,
int isdisplaying)
{
    if (value > 0 && flag_utils.flag != 'u') {
        if (isdisplaying)
            my_putchar('+');
        len++;
    }
    return (len);
}

int fflag_space_int(int len, valuesbox_t flag_utils, int value,
int isdisplaying)
{
    if (isdisplaying && flag_utils.width == 0)
        my_putchar(' ');
    return (len);
}

int fflag_hashtag_int(int len, valuesbox_t flag_utils, int value,
int isdisplaying)
{
    return (len);
}

int fflag_zero_int(int len, valuesbox_t flag_utils, int value,
int isdisplaying)
{
    thefor(flag_utils.width, len, '0');
    return (flag_utils.width);
}
