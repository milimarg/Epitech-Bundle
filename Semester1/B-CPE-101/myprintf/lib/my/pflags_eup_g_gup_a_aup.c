/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** vabs_list.c
*/

#include "../../include/funcs_struct_proto.h"

int check_eup(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    double value = va_arg(list, double);
    int width = fflag_output[1];
    char *values[] = {flag_utils.flag_res, "E"};
    int precision = (fflag_output[2] == 'p') ? fflag_output[3] : 6;
    int len_local = my_put_science(value, values[1][0], 0, precision);

    flag_utils.symbols_allowed = "+ -0";
    flag_utils.width = width;
    len_local = check_fflag_float(len_local, flag_utils, value, 0);
    if (width > 0)
        len += thefor(width, len_local, ' ');
    check_fflag_float(len_local, flag_utils, value, 1);
    len = my_put_science(value, values[1][0], 1, precision);
    if (width < 0)
        len += thefor(width, len_local, ' ');
    return (len);
}

int check_g(va_list list, int len, int *fflag_output)
{
    return len;
}

int check_gup(va_list list, int len, int *fflag_output)
{
    return len;
}

int check_a(va_list list, int len)
{
    return len;
}

int check_aup(va_list list, int len, int *fflag_output)
{
    return len;
}
