/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** Hello world
*/

static char size(int *i, int *h, char *dest, char const *src)
{
    while (dest[*i] != '\0') {
        ++*i;
    }
    while (src[*h] != '\0') {
        ++*h;
    }
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int h = 0;
    int k = 0;
    int a = 0;
    int b = 0;
    size(&i, &h, dest, src);
    while (k < i + nb) {
        if (k < i) {
            dest[a] = dest[a];
            a++;
        }
        if (k >= i) {
            dest[k] = src[b];
            b++;
        }
        k++;
    }
    return (dest);
}
