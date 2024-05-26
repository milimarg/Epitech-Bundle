/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#include <stdio.h>
#include <stdlib.h>

static int its_separator(char *separator, char c)
{
    int i = 0;
    while (separator[i] != '\0') {
        if (c == separator[i])
            return (0);
        i++;
    }
    return (1);
}

static int count_word(char *str, char *separator)
{
    int i = 0;
    int result = 0;
    if (its_separator(separator, str[0]) != 0)
        result = 1;
    while (str[i] != '\0') {
        if (its_separator(separator, str[i]) != 0 &&
        its_separator(separator, str[i - 1]) == 0)
            result++;
        i++;
    }
    return (result);
}

static int calculate_size_word(char *str, char *separator, int i)
{
    int a = 0;
    int index = 0;
    int result = 0;
    while (its_separator(separator, str[a]) == 0)
        a++;
    while (str[a] != '\0') {
        if (its_separator(separator, str[a]) == 0)
            index++;
        while (its_separator(separator, str[a]) == 0)
            a++;
        if (index == i && its_separator(separator, str[a]) != 0)
            result++;
        a++;
    }
    return (result);
}

static char *fill_good_word(int i, int size_word, char *str, char *separator)
{
    char *tmp = malloc(sizeof(char) * (size_word + 1));
    int a = 0;
    int index = 0;
    int result = 0;

    if (tmp == NULL)
        return (NULL);
    for (; its_separator(separator, str[a]) == 0; a++);
    for (; str[a] != '\0'; a++) {
        if (its_separator(separator, str[a]) == 0)
            index++;
        while (its_separator(separator, str[a]) == 0)
            a++;
        if (index == i && its_separator(separator, str[a]) != 0) {
            tmp[result] = str[a];
            result++;
        }
    }
    tmp[result] = '\0';
    return (tmp);
}

char **my_str_to_word_array_condition(char *str, char *separator)
{
    int nbr_word = count_word(str, separator);
    char **array = malloc(sizeof(char *) * (nbr_word + 1));
    int i = 0;
    int size_word = 0;

    if (array == NULL)
        return (NULL);
    while (i < nbr_word) {
        size_word = calculate_size_word(str, separator, i);
        array[i] = malloc(sizeof(char) * (size_word + 1));
        array[i] = fill_good_word(i, size_word, str, separator);
        if (array[i] == NULL)
            return (NULL);
        i++;
    }
    array[i] = NULL;
    return (array);
}
