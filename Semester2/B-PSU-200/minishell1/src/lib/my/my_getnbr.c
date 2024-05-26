/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    int nb = 0;

    while (str[i] == '-' || str[i] == '+')
        neg *= (str[i++] == '-') ? (-1) : 1;
    for (; str[i] >= '0' && str[i] <= '9'; i++)
        nb = (nb * 10) + (str[i] - '0');
    return (nb * neg);
}
