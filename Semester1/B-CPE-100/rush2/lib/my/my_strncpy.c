/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** Replaces string by another of lenght 'n'.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; src[i] != src[n]; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
