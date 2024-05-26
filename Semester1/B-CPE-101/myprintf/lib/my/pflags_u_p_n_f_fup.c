/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** vabs_list2.c
*/

#include <stdlib.h>
#include "../../include/funcs_struct_proto.h"

int check_u(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    int value = va_arg(list, int);
    int width = fflag_output[1];
    int len_local = my_intlen(value);

    flag_utils.symbols_allowed = "+0";
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

int check_p(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    char *values[] = {flag_utils.flag_res, "0123456789abcdef"};
    long int value = va_arg(list, void *);
    int width = fflag_output[1];
    int len_local = my_putnbr_base(value, values[1], 0);

    len_local += (flag_utils.flag == 'p') ? 2 : 0;
    flag_utils.symbols_allowed = "+- 0";
    flag_utils.width = width;
    if (flag_utils.flag == 'p' && value < 0)
        value += 4294967296;
    len_local = check_fflag_putnbr_base(len_local, flag_utils, value, 0);
    if (width > 0)
        len += thefor(width, len_local, ' ');
    check_fflag_putnbr_base(len_local, flag_utils, value, 1);
    len = my_putnbr_base_helper(fflag_output, len, value, values);
    if (width < 0)
        len += thefor(width, len_local, ' ');
    return (len);
}

int check_n(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    int *adresse = va_arg(list, int *);

    *adresse = len;
    return len;
}

int check_f(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    double value = va_arg(list, double);
    int width = fflag_output[1];
    int precision = (fflag_output[2] == 'p') ? fflag_output[3] : 6;
    int len_local = my_put_float(value, precision, 0);

    flag_utils.symbols_allowed = "+ -0#";
    flag_utils.width = width;
    len_local = check_fflag_float(len_local, flag_utils, value, 0);
    if (width > 0)
        len += thefor(width, len_local, ' ');
    check_fflag_float(len_local, flag_utils, value, 1);
    len = my_putfloat_helper(fflag_output, len, value, flag_utils.flag_res);
    if (width < 0)
        len += thefor(width, len_local, ' ');
    return (len);
}

int check_fup(va_list list, int len, int *fflag_output, valuesbox_t flag_utils)
{
    double value = va_arg(list, double);
    int width = fflag_output[1];
    int precision = (fflag_output[2] == 'p') ? fflag_output[3] : 6;
    int len_local = my_put_float(value, precision, 0);

    flag_utils.symbols_allowed = "+ -0#";
    flag_utils.width = width;
    len_local = check_fflag_float(len_local, flag_utils, value, 0);
    if (width > 0)
        len += thefor(width, len_local, ' ');
    check_fflag_float(len_local, flag_utils, value, 1);
    len = my_putfloat_helper(fflag_output, len, value, flag_utils.flag_res);
    if (width < 0)
        len += thefor(width, len_local, ' ');
    return (len);
}
