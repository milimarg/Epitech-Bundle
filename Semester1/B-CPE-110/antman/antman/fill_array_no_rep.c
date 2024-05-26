/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/antman.h"

int subdivision_count_word(char **array, int i, int a)
{
    if (my_strcmp(array[i], array[a]) == 0)
        return (1);
    else
        return (0);
}

int count_dif_word(char **array)
{
    int i = 0;
    int a = 0;
    int value = 0;
    int result = 0;

    while (array[i]) {
        a = 0;
        value = 0;
        while (a < i) {
            value = value + subdivision_count_word(array, i, a);
            a++;
        }
        if (value == 0)
            result++;
        i++;
    }
    return (result);
}

int subdivision_fill_array(char **array, int i, int a)
{
    return ((my_strcmp(array[i], array[a]) == 0 &&
    my_strlen(array[i]) == my_strlen(array[a])));
}

char ** fill_the_array(char **array_no_rep, char **array)
{
    int i = 0;
    int a = 0;
    int value = 0;
    int result = 0;
    int index = 0;

    while (array[i]) {
        a = 0;
        value = 0;
        while (a < i) {
            value = value + subdivision_fill_array(array, i, a++);
        }
        if (value == 0) {
            array_no_rep[index] = array[i];
            index++;
        }
        i++;
    }
    array_no_rep[index] = NULL;
    return (array_no_rep);
}
