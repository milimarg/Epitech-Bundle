/*
** EPITECH PROJECT, 2022
** CPOOL_Day10_task02
** File description:
** do_op.c
*/

#include "../include/my.h"

int calc(int value1, int value2, char op);

char get_operator(char *op);

int do_op(char *value1, char *op, char *value2)
{
    char used_op;
    int result;
    int value_1 = my_getnbr(value1);
    int value_2 = my_getnbr(value2);

    used_op = get_operator(op);
    result = calc(value_1, value_2, used_op);
    //my_put_nbr(result);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 4)
        do_op(argv[1], argv[2], argv[3]);
    return 0;
}
