/*
** EPITECH PROJECT, 2022
** CPOOL_Day04
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
