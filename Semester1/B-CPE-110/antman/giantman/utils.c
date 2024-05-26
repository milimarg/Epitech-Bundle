/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-antman-florent.guittre
** File description:
** utils
*/

#include <stdlib.h>

int get_number_len(int nb)
{
    int len = 0;

    if (nb >= 0 && nb <= 9)
        len = 1;
    if (nb >= 10 && nb <= 99)
        len = 2;
    if (nb >= 100 && nb <= 999)
        len = 3;
    return (len);
}

void display_nb(int nb, char *values, int *char_index)
{
    if (nb == 0)
        return;
    display_nb(nb / 10, values, char_index);
    values[(*char_index)++] = (nb % 10) + '0';
}

int t_my_strncmp(const char *s1, const char *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (*s1 != *s2)
            return (1);
        s1++;
        s2++;
    }
    return (0);
}
