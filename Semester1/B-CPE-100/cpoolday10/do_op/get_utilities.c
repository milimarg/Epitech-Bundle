/*
** EPITECH PROJECT, 2022
** CPOOL_Day10_task02
** File description:
** get_utilities.c
*/

#include "../include/my.h"

int calc(int value1, int value2, char op)
{
    int o;

    o = 0;
    if (value2 == 0 && op == '/')
        my_putstr("Stop: division by zero");
    if (value2 == 0 && op == '%')
        my_putstr("Stop: modulo by zero");
    if (op == '+')
        o = value1 + value2;
    if (op == '-')
        o = (value1) - (value2);
    if (op == '*')
        o = value1 * value2;
    if (op == '/' && value2 != 0)
        o = value1 / value2;
    if (op == '%' && value2 != 0)
        o = value1 % value2;
    return o;
}

char get_operator(char *op)
{
    char operators[5] = {'+', '-', '*', '/', '%'};
    char result;
    int temp;

    result = '.';
    for (int i = 0; op[i] != '\0'; i++) {
        for (int j = 0; j < 5; j++) {
            temp = (my_find_char(op, operators[j]));
            if (temp) {
                result = operators[j];
                break;
            }
        }
    }
    return result;
}
