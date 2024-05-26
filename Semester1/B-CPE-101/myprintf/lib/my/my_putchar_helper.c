/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** my_putchar_helper.c
*/

#include "../../include/funcs_struct_proto.h"

int my_putchar_helper(int *fflag_output, int len, char char_value,
char *flag_res)
{
    int len_local = 1;
    int width = fflag_output[1];

    if (fflag_output[0] != 'e') {
        if (width > 0)
            len += thefor(width, len_local, ' ');
        my_putchar(char_value);
        if (width < 0)
            len += thefor(width, len_local, ' ');
    } else {
        len += my_strlen(flag_res);
        my_putstr(flag_res);
    }
    return (len);
}
