/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-antman-florent.guittre
** File description:
** html_compression_utils
*/

#include <stdlib.h>
#include "../include/giantman.h"
#include "../include/my.h"

char **just_need(char **array)
{
    int i = 0;
    int nbr = 0;
    int b = 0;
    char **result = NULL;

    while (array[i]) {
        nbr = (array[i][0] >= '0' && array[i][0] <= '9') ? nbr + 1 : nbr;
        i++;
    }
    result = malloc(sizeof(char *) * (nbr + 1));
    if (result == NULL)
        return (NULL);
    for (i = 0; array[i]; i++) {
        result[b] = (array[i][0] >= '0' && array[i][0] <= '9') ? array[i] :
        result[b];
        b = (array[i][0] >= '0' && array[i][0] <= '9') ? b + 1 : b;
    }
    result[b] = NULL;
    return (result);
}

int find_size(char *str)
{
    char **array = my_str_to_word_array_condition(str, "|");
    char **new_array = just_need(array);
    int value = 0;
    int a = 0;

    if (new_array == NULL || array == NULL)
        return (-84);
    while (new_array[a]) {
        if (a % 2 != 0) {
            value = value + my_getnbr(new_array[a]);
        }
        a++;
    }
    return (value);
}

char **create_local_tab(char *str, int i)
{
    int a = i;
    int b = 0;
    int index = 0;
    char *tmp = NULL;
    char **output = NULL;

    for (; index != 3; a++)
        index = (str[a] == '|') ? index + 1 : index;
    tmp = malloc(sizeof(char) * (a - i + 1));
    if (tmp == NULL)
        return (NULL);
    for (index = 0, a = i; index != 3;) {
        index = (str[a] == '|') ? index + 1 : index;
        tmp[b++] = str[a++];
    }
    tmp[b] = '\0';
    output = my_str_to_word_array_condition(tmp, "|");
    free(tmp);
    return (output);
}

int calculate_size_pip(char *str, int i)
{
    int a = i;
    int index = 0;

    while (index != 3) {
        if (str[a] == '|')
            index++;
        a++;
    }
    return (a - i);
}

int store_buffer(char *str, char *buffer, int *i, int *a)
{
    char **local_tab = create_local_tab(str, *i);
    int size_pip = calculate_size_pip(str, *i);
    int j = 0;
    int tmp = *a;
    int value = my_getnbr(local_tab[0]);

    if (local_tab == NULL)
        return (84);
    while (j < my_getnbr(local_tab[1])) {
        buffer[*a] = buffer[tmp - value];
        value--;
        (*a)++;
        j++;
    }
    (*i) += size_pip;
    return (0);
}
