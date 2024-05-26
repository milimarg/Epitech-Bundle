/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** my_putstr_helper.c
*/

#include "../../include/funcs_struct_proto.h"

int my_putstr_helper(int *fflag_output, int len, char *string_value,
char *flag_res)
{
    int len_local = my_strlen(string_value);
    int width = fflag_output[1];

    if (fflag_output[0] != 'e') {
        len += (width - len_local >= 0) ? width : len_local;
        if (width > 0)
            thefor(width, len_local, ' ');
        my_putstr(string_value);
        if (width < 0)
            thefor(width, len_local, ' ');
    } else {
        len += my_strlen(flag_res);
        my_putstr(flag_res);
    }
    return (len);
}
