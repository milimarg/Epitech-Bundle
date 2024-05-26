/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** vabs_list.c
*/

#include "../../include/funcs_struct_proto.h"

int check_d(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    int value = va_arg(list, int);
    int width = fflag_output[1];
    int len_local = my_intlen(value);

    flag_utils.symbols_allowed = "+ -0";
    flag_utils.width = width;
    len_local = check_fflag_int(len_local, flag_utils, value, 0);
    if (width > 0)
        len += thefor(width, len_local, ' ');
    check_fflag_int(len_local, flag_utils, value, 1);
    len = my_put_int_helper(fflag_output, len, value, flag_utils);
    if (width < 0)
        len += thefor(width, len_local, ' ');
    return (len);
}

int check_i(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    int value = va_arg(list, int);
    int width = fflag_output[1];
    int len_local = my_intlen(value);

    flag_utils.symbols_allowed = "+ -0";
    len_local = check_fflag_int(len_local, flag_utils, value, 0);
    if (width > 0)
        len += thefor(width, len_local, ' ');
    check_fflag_int(len_local, flag_utils, value, 1);
    len = my_put_int_helper(fflag_output, len, value, flag_utils);
    if (width < 0)
        len += thefor(width, len_local, ' ');
    return (len);
}

int check_s(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    char *string_value = va_arg(list, char *);

    return (my_putstr_helper(fflag_output, len, string_value,
    flag_utils.flag_res));
}

int check_c(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    char char_value = va_arg(list, int);

    return (my_putchar_helper(fflag_output, len, char_value,
    flag_utils.flag_res));
}

int check_prc(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    len++;
    my_putchar('%');
    return len;
}
