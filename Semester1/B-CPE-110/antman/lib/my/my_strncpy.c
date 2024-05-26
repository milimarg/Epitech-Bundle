/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** I'm hungry
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n > i) {
        dest[i] = '\0';
    }
    return (dest);
}
