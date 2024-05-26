/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** vabs_list.c
*/

#include "../../include/funcs_struct_proto.h"

int check_sup(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    char *value = va_arg(list, char *);

    return (my_putstr_full(value, 1, len));
}

int check_o(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    char *values[] = {flag_utils.flag_res, "01234567"};
    long value = va_arg(list, long);
    int width = fflag_output[1];
    int len_local = my_putnbr_base(value, values[1], 0);

    flag_utils.symbols_allowed = "# -0";
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

int check_x(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    char *values[] = {flag_utils.flag_res, "0123456789abcdef"};
    long value = va_arg(list, long);
    int width = fflag_output[1];
    int len_local = my_putnbr_base(value, values[1], 0);

    flag_utils.symbols_allowed = "-0#";
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

int check_xup(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    char *values[] = {flag_utils.flag_res, "0123456789ABCDEF"};
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

int check_e(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    double value = va_arg(list, double);
    int width = fflag_output[1];
    char *values[] = {flag_utils.flag_res, "e"};
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
