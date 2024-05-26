/*
** EPITECH PROJECT, 2022
** CPOOL_mini_printf
** File description:
** vabs_list.c
*/

#include <stdarg.h>
#include "./include/proto.h"

int check_d(va_list list, int len)
{
    int int_value = va_arg(list, int);
    len += my_intlen(int_value);
    my_put_nbr(int_value);
    return len;
}

int check_i(va_list list, int len)
{
    int int_value = va_arg(list, int);
    len += my_intlen(int_value);
    my_put_nbr(int_value);
    return len;
}

int check_s(va_list list, int len)
{
    char *string_value = va_arg(list, char*);
    len += my_strlen(string_value);
    my_putstr(string_value);
    return len;
}

int check_c(va_list list, int len)
{
    char char_value = va_arg(list, int);
    len++;
    my_putchar(char_value);
    return len;
}

int check_percentage(va_list list, int len)
{
    len++;
    my_putchar('%');
    return len;
}
