/*
** EPITECH PROJECT, 2022
** CPOOL_Day06
** File description:
** my_strncpy.c
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    for (i; i < n; i++)
        dest[i] = '\0';
    return dest;
}
