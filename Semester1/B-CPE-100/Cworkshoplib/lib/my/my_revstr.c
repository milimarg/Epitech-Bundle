/*
** EPITECH PROJECT, 2022
** CPOOL_CWorkshopLib
** File description:
** my_revstr.c
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j;
    char z;

    while (str[i] != '\0')
        i++;
    for (j = 0; j < i / 2; j++) {
        z = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = z;
    }
    return str;
}
