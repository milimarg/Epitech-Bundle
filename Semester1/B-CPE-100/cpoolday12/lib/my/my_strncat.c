/*
** EPITECH PROJECT, 2022
** CPOOL_CWorkshopLib
** File description:
** my_strncat.c
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0' && i < nb) {
        dest[i + dest_len] = src[i];
        i++;
    }
    dest[i + dest_len] = '\0';
    return dest;
}
