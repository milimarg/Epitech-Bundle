/*
** EPITECH PROJECT, 2022
** CPOOL_Day06
** File description:
** my_strcpy.c
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
