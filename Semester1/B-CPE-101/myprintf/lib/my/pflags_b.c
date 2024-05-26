/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** vabs_list.c
*/

#include "../../include/funcs_struct_proto.h"

int thefor(int width, int len_local, char space)
{
    width *= (width < 0) ? (-1) : 1;
    for (int i = 0; i < (width - len_local); i++)
        my_putchar(space);
    return ((width - len_local <= 0) ? len_local : width);
}

int check_b(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    char *values[] = {flag_utils.flag_res, "01"};
    long value = va_arg(list, long);
    int width = fflag_output[1];
    int len_local = my_putnbr_base(value, values[1], 0);

    flag_utils.symbols_allowed = "#-0";
    flag_utils.width = width;
    len_local = check_fflag_putnbr_base(len_local, flag_utils, value, 0);
    if (width > 0)
        len += thefor(width, len_local, ' ');
    check_fflag_putnbr_base(len_local, flag_utils, value, 1);
    len = my_putnbr_base_helper(fflag_output, len, value, values);
    if (width < 0)
        len += thefor(width, len_local, ' ');
    return (len);
}
