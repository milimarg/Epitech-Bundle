/*
** EPITECH PROJECT, 2022
** CPOOL_Day05
** File description:
** my_getnbr.c
*/

int my_char_isnum(const char c);

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
