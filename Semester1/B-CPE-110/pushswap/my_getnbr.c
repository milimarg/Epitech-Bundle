/*
** EPITECH PROJECT, 2022
** CPOOL_CWorkshopLib
** File description:
** my_getnbr.c
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    int nb = 0;

    while (str[i] == '-' || str[i] == '+') {
        neg *= (str[i] == '-') ? (-1) : 1;
        i++;
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        nb *= 10;
        nb += (str[i] - '0');
    }
    nb *= neg;
    return (nb);
}
