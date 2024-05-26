/*
** EPITECH PROJECT, 2022
** nbrlen.c
** File description:
** la longueur d'un nombre
*/

int my_nbrlen(int long nb)
{
    int i = 0;
    if (nb < 0) {
        nb = -nb;
        i++;
    }
    while (nb > 9) {
        i++;
        nb = nb / 10;
    }
    return i + 1;
}
