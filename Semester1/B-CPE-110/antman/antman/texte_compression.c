/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#include "../include/my.h"
#include "../include/antman.h"
#include "../include/antman_structs.h"

int check_occurences(char *str, antman_idx *idx, int value)
{
    idx->a = 0;
    idx->temp_i = idx->i;
    while (idx->a < idx->i) {
        idx->temp_i = idx->i;
        idx->temp_a = idx->a;
        value = 0;
        while (str[idx->a] == str[idx->i] && idx->a < idx->temp_i) {
            idx->a++;
            idx->i++;
            value++;
        }
        if (value <= 7)
            value = 0;
        else
            break;
        idx->i = idx->temp_i;
        idx->a = idx->temp_a + 1;
    }
    return (value);
}

int texte_compression(int ac, char **av, char *str)
{
    antman_idx idx = {0};
    int value = 0;

    while (str[idx.i] != '\0') {
        value = 0;
        value = check_occurences(str, &idx, value);
        if (value != 0) {
            my_putchar('|');
            my_put_nbr_len(idx.temp_i - idx.temp_a);
            my_putchar('|');
            my_put_nbr_len(value);
            my_putchar('|');
            idx.i = idx.temp_i + value;
        } else {
            my_putchar(str[idx.i]);
            idx.i = idx.temp_i;
            idx.i++;
        }
    }
    return (0);
}
