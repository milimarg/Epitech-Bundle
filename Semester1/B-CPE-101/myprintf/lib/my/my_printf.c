/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** my_printf.c
*/

#include <stdlib.h>
#include "../../include/funcs_struct_proto.h"

int is_flag(valuesbox_t flag_utils, char vabs[], int vab_nb)
{
    char flag = flag_utils.flag;
    int is_flag_separated = flag_utils.is_flag_separated;
    int o = 0;

    for (int i = 0; i < vab_nb; i++)
        if (vabs[i] == flag) {
            o++;
        }
    if (!o) {
        my_putchar('%');
        if (is_flag_separated)
            my_putchar(' ');
        my_putchar(flag);
    }
    return o;
}

valuesbox_t register_flag_chars(const char *format, int i, char vabs[])
{
    valuesbox_t flag_utils;
    int a = 0;
    int format_len = my_strlen(format);
    int vab_nb = my_strlen(vabs);

    flag_utils.flag_res = malloc(sizeof(char) * 1000);
    flag_utils.flag_res[a++] = format[i++];
    flag_utils.flag = 1;
    while (flag_utils.flag == 1) {
        for (int z = 0; z < vab_nb; z++) {
            flag_utils.flag_res[a] = (!z) ?
            format[i + a - 1] : flag_utils.flag_res[a];
            flag_utils.flag = (char_alpha(format[i + a - 1]) ||
            format[i + a - 1] == '%') ? format[i + a - 1] : flag_utils.flag;
        }
        a++;
    }
    flag_utils.i = i + a - 1;
    flag_utils.is_flag_separated = (a > 2);
    return flag_utils;
}

valuesbox_t check_flag(valuesbox_t values, const char *format,
va_list list, char vabs[])
{
    int vab_nb = values.vab_nb;
    int flag_res_len = 0;
    char flag = '.';
    valuesbox_t flag_utils;

    if (format[values.i] == '%') {
        if (format[values.i + 1] == '\0')
            return (values);
        flag_utils = register_flag_chars(format, values.i, vabs);
        values.i = flag_utils.i - 1;
        if (is_flag(flag_utils, vabs, vab_nb))
            values.len = pflag_replacer(vab_nb, flag_utils, list, values.len);
        free(flag_utils.flag_res);
    } else {
        my_putchar(format[values.i]);
        values.len++;
    }
    return (values);
}

int my_printf(const char *format, ...)
{
    va_list list;
    valuesbox_t values;
    char *vabs = "disc%SupfnFoxXeEgGaAb";

    values.vab_nb = my_strlen(vabs);
    values.len = 0;
    va_start(list, format);
    for (values.i = 0; format[values.i] != '\0'; values.i++) {
        values = check_flag(values, format, list, vabs);
    }
    va_end(list);
    return (values.len);
}
