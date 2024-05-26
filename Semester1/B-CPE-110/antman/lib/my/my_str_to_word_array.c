/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** good prog
*/

#include <stdlib.h>
#include "my.h"

static int number_off(int i, char const *str, int j, int *h)
{
    int r = 0;
    int c = 0;
    int result;
    while (r < i) {
        while ((str[*h] < 48) || (str[*h] > 57 && str[*h] < 65) ||
            (str[*h] > 90 && str[*h] < 97) || (str[*h] > 122)) {
            ++(*h);
        }
        c = *h;
        while ((str[*h] <= 57 && str[*h] >= 48) ||
            (str[*h] >= 97 && str[*h] <= 122)
            || (str[*h] >= 65 && str[*h] <= 90)) {
            ++(*h);
        }
        result = c;
        if (r = (i - 1)){
            return (result);
        }
        r++;
    }
}

static int size_off(int i, char const *str, int j, int *a)
{
    int r = 0;
    int b = 0;
    int result;
    while (r < i) {
        while ((str[*a] < 48) || (str[*a] > 57 && str[*a] < 65) ||
            (str[*a] > 90 && str[*a] < 97) || (str[*a] > 122))
            ++(*a);
        while ((str[*a] <= 57 && str[*a] >= 48) ||
            (str[*a] >= 97 && str[*a] <= 122)
            || (str[*a] >= 65 && str[*a] <= 90)) {
            ++(*a);
            b++;
        }
        result = b;
        if (r = (i - 1)){
            return (result);
        }
        r++;
    }
}

static char *put_string(int point, char const *str, int mult)
{
    char *dest = malloc(sizeof(char) * (mult + 1));
    int f = 0;

    if (dest == NULL)
        return (NULL);
    while (f < mult) {
        dest[f] = str[point];
        point++;
        f++;
    }
    return (dest);
}

static void alphanum (int *i,int *j, char const *str)
{
    while (str[*i] != '\0') {
        if (((str[*i] <= 57 && str[*i] >= 48) ||
            (str[*i] >= 97 && str[*i] <= 122) ||
            (str[*i] >= 65 && str[*i] <= 90)) && ((str[*i - 1] < 48) ||
            (str[*i - 1] > 57 && str[*i - 1] < 65) ||
            (str[*i - 1] > 90 && str[*i - 1] < 97) ||
            (str[*i - 1] > 122))){
            ++*j;
        }
        ++*i;
    }
}

char **my_str_to_word_array(char const *str)
{
    int i = 0, j = 0, g = 0 , a = 0, h = 0, mult = 0, point = 0;
    char **tab;
    alphanum (&i, &j, str);
    tab = malloc(sizeof(char *) * j);
    while (g <= j) {
        mult = size_off(i, str, j, &a);
        point = number_off(i, str, j, &h);
        tab[g] = malloc(sizeof(char) * (mult + 1));
        tab[g] = put_string(point, str, mult);
        if (tab[g] == NULL)
            return (NULL);
        g++;
        if (g == (j + 1)) {
            tab[g - 1] = '\0';
        }
    }
    return (tab);
}
