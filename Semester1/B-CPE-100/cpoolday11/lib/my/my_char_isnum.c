/*
** EPITECH PROJECT, 2022
** CPOOL_Day07
** File description:
** my_char_isnum.c
*/

int my_char_isnum(char const c)
{
    int o;

    o = (c >= '0' && c <= '9');
    return o;
}
