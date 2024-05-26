/*
** EPITECH PROJECT, 2022
** CPOOL_Day06
** File description:
** my_revstr.c
*/

char *my_revstr(char *str)
{
    int i;
    int j;
    char z;

    i = 0;
    while (str[i] != '\0')
        i++;
    for (j = 0; j < i / 2; j++) {
        z = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = z;
    }
    return str;
}
