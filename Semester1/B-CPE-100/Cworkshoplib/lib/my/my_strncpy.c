/*
** EPITECH PROJECT, 2022
** CPOOL_CWorkshopLib
** File description:
** my_strncpy.c
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    for (i; i < n; i++)
        dest[i] = '\0';
    return dest;
}
