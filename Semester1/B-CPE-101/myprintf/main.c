/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** main.c
*/

#include <stdio.h>
#include "./include/funcs_struct_proto.h"

int my_printf(const char *format, ...);

int main(void)
{
    int my_len = 0;
    int len = 0;
    char *str = "Hello '%-5x' everybody";
    int vab = 100;

    my_putstr("my_printf:\n");
    my_len = my_printf(str, vab);
    my_putchar('\n');
    my_putstr("printf:\n");
    len = printf(str, vab);
    int len=0;
    return (0);
}