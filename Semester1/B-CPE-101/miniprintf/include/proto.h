/*
** EPITECH PROJECT, 2022
** CPOOL_mini_printf
** File description:
** proto.h
*/

#ifndef PROTO_H
    #define PROTO_H
    #include <stdarg.h>
void my_putchar(char c);
void my_putstr(const char *str);
int my_strlen(const char *str);
int my_intlen(int nb);
int my_put_nbr(int nb);
int check_vab_manager(int vab_number, int vab_index, va_list list, int len);
int check_d(va_list list, int len);
int check_i(va_list list, int len);
int check_s(va_list list, int len);
int check_c(va_list list, int len);
int check_percentage(va_list list, int len);
#endif
