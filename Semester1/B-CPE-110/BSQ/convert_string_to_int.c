/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** convert_string_to_int.c
*/

int my_char_isnum(char const c)
{
    int o;

    o = (c >= '0' && c <= '9');
    return o;
}

int my_getnbr(char const *str)
{
    int i;
    int neg;
    int nb;

    i = 0;
    neg = 1;
    nb = 0;
    while (str[i] == '-' || str[i] == '+') {
        neg *= (str[i] == '-') ? (-1) : 1;
        i++;
    }
    for (i; my_char_isnum(str[i]); i++) {
        nb *= 10;
        nb += (str[i] - '0');
    }
    nb *= neg;
    return nb;
}
