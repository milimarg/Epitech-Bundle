/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

int tabeau(int a, va_list list_arg, int count)
{
    int(*board[18])(va_list, int) = {&plus_flag, &print_int, &print_char,
    &print_str, &print_int, &print_unsi, &my_print_purcent, &print_octal,
    &print_hexa_maj, &print_hexa_min, &printn, &print_adress, &my_binary,
    &my_binary, &print_float, &print_float, &print_scien, &print_scienup};
    return (board[a](list_arg, count));
}

int erreur(int k, int count)
{
    if (k == 0) {
        write(2, "ERROR", 5);
        return -1;
    }
    return count;
}

int argument(const char *format, int *i, va_list list_arg, int count)
{
    int k = 0;
    int a = 0;
    if (format[*i] == ' ')
        *i = print_space(format, *i);
    char flag_di[19] = {'+', 'd', 'c', 's', 'i', 'u', '%', 'o', 'X', 'x', 'n',
    'p', 'b', 'B', 'f', 'F', 'e', 'E', '\0'};
    while (flag_di[a] != '\0') {
        if (flag_di[a] == format[*i]) {
            k = 1;
            count = tabeau(a, list_arg, count);
        }
        if (k == 1 && a < 1) {
            *i = *i + 1;
            k = 0;
            a = 0;
        }
        a++;
    }
    return erreur(k, count);
}

int my_printf(const char *format, ...)
{
    va_list list_arg;
    va_start(list_arg, *format);
    int count = 0;

    for (int i = 0; format[i] != '\0'; i++) {
        if (count == -1) {
            va_end(list_arg);
            return -1;
        }
        if (format[i] != '%') {
            count++;
            my_putchar(format[i]);
        } else {
            i++;
            count = argument(format, &i, list_arg, count);
        }
    }
    va_end(list_arg);
    return 0;
}
