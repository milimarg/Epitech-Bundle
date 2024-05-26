/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** task04
*/

#include <stdlib.h>

int my_strlen(char const *str);

int my_getnbr(char const *str);

void count_for_mem(char const *str, int *i, int *count, char *word)
{
    *count = 0;
    while (str[*i] != ' ' && str[*i] != '\0') {
        (*count)++;
        (*i)++;
    }
}

void count_for_print(char const *str, int *i, char *word, int *count)
{
    *count = 0;
    while (str[*i] != ' ' && str[*i] != '\0') {
        word[*count] = str[*i];
        (*i)++;
        (*count)++;
    }
    word[*count] = '\0';
}

int count_lines(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ')
            count++;
    }
    return count;
}

char **my_str_to_word_array(char const *str)
{
    int count = 0;
    int count_array = 0;
    int sauv = 0;
    char *word;
    char **array;
    int len = my_strlen(str);
    int lines = count_lines(str);

    array = malloc(sizeof(char *) * (lines + 2));
    for (int i = 0; i < len; i++) {
        sauv = i;
        count_for_mem(str, &i, &count, word);
        word = malloc(sizeof(char) * (count + 1));
        i = sauv;
        count_for_print(str, &i, word, &count);
        array[count_array] = word;
        count_array++;
    }
    array[count_array] = NULL;
    return array;
}
