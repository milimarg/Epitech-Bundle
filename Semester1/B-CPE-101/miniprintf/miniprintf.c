/*
** EPITECH PROJECT, 2022
** CPOOL_mini_printf
** File description:
** miniprintf.c
*/

#include <stdarg.h>
#include "./include/proto.h"
#include "./include/my_struct.h"

int check_vab_manager(int vab_nb, int vab_index, va_list list, int len)
{
    int (*fptr[vab_nb])(va_list, int);
    int (*ptr[5])(va_list, int) =
    {&check_d, &check_i, &check_s, &check_c, &check_percentage};

    for (int z = 0; z < vab_nb; z++)
        fptr[z] = ptr[z];
    len = fptr[vab_index](list, len);
    return len;
}

void check_vab_exists(const char *format, valuesbox_t values, int j,
char vabs[])
{
    int i = values.i;
    int vab_nb = values.vab_nb;
    int y = 0;

    for (int x = 0; x < vab_nb; x++)
        if (format[i] == '%' && format[i + 1] == vabs[x])
            y++;
    if (format[i] == '%' && !y && !(j % vab_nb))
        my_putchar('%');
}

valuesbox_t check_vab(int j, valuesbox_t values, const char *format,
va_list list)
{
    int i = values.i;
    int len = values.len;
    int vab_nb = values.vab_nb;
    char vabs[5] = {'d', 'i', 's', 'c', '%'};

    check_vab_exists(format, values, j, vabs);
    if ((format[i] == '%' && format[i + 1] == vabs[j])) {
        len = check_vab_manager(vab_nb, j, list, len);
        i++;
    } else if (j % vab_nb == 0 && format[i] != '%') {
        my_putchar(format[i]);
        len++;
    }
    values.i = i;
    values.len = len;
    return (values);
}

int mini_printf(const char *format, ...)
{
    va_list list;
    valuesbox_t values;
    int len = 0;
    int vab_nb = 5;

    values.vab_nb = vab_nb;
    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        for (int j = 0; j < vab_nb; j++) {
            values.i = i;
            values.len = len;
            values = check_vab(j, values, format, list);
            i = values.i;
            len = values.len;
        }
    }
    va_end(list);
    return (len);
}
