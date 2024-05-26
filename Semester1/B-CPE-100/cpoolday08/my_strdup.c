/*
** EPITECH PROJECT, 2022
** CPOOL_Day08
** File description:
** my_strdup.c
*/

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len;
    char *dest;
    int i;

    len = my_strlen(src);
    dest = malloc(sizeof(char) * (len + 1));
    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
