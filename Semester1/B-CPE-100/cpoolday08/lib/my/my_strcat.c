/*
** EPITECH PROJECT, 2022
** CPOOL_Day07
** File description:
** my_strcat.c
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int dest_len;
    int i;

    i = 0;
    dest_len = my_strlen(dest);
    while (src[i] != '\0') {
        dest[i + dest_len] = src[i];
        i++;
    }
    dest[i + dest_len] = '\0';
    return dest;
}
