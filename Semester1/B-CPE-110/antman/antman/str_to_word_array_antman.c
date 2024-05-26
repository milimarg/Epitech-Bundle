/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/antman.h"

int count_word(char *str)
{
    int i = 0;
    int result = 0;
    if (str[0] = 32) {
        result = result + 1;
    }
    while (str[i] != '\0') {
        if (str[i] == 32 && str[i + 1] != 32)
            result = result + 1;
        i++;
    }
    return (result);
}

int calculate_size_word(int i, char *str)
{
    int a = 0;
    int value = 0;
    int index = 0;

    while (str[a] != '\0') {
        if (str[a] != 32)
            value++;
        if (index == i && value != 0 && (str[a] == 32 || str[a + 1] == '\0')) {
            return (value);
        }
        if (value != 0 && str[a] == 32) {
            value = 0;
            index++;
        }
        a++;
    }
}

char* select_word(int i, char *str, int size_word)
{
    int a = 0;
    int b = 0;
    int touch = 0;
    int index = 0;
    char *word = malloc(sizeof(char) * (size_word + 2));

    if (word == NULL)
        return (NULL);
    while (str[a] != '\0') {
        if (index == i && str[a] != 32) {
            word[b] = str[a];
            b++;
        } if (str[a] != 32)
            touch++;
        if (touch != 0 && str[a + 1] == 32)
            index++;
        a++;
    }
    word[b] = '\0';
    return (word);
}

char **str_to_word_array_antman(char *str)
{
    int nbr_word = count_word(str);
    char **array = malloc(sizeof(char *) * (nbr_word + 1));
    int i = 0;
    int size_word = 0;

    if (array == NULL)
        return (NULL);
    while (i < nbr_word - 1) {
        size_word = calculate_size_word(i, str);
        if (i == 0)
            size_word++;
        array[i] = malloc(sizeof(char) * (size_word + 1));
        array[i] = select_word(i, str, size_word);
        if (array[i] == NULL)
            return (NULL);
        i++;
    }
    array[i] = NULL;
    return (array);
}
