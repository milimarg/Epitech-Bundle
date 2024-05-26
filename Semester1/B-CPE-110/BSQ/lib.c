/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** lib.c
*/

#include <stdlib.h>

int my_char_isalpha(char const c)
{
    int check = 0;

    if (c > 'a' && c < 'z')
        check++;
    if (c > 'A' && c < 'Z')
        check++;
    return (check >= 1);
}

int *count_words_len(char const *str, int words_nb, char separator, int size)
{
    int i = 0;
    int k = 0;
    int next_index = 0;
    int *full_len = malloc(sizeof(int) * (words_nb + 1));

    while (i < size) {
        if (str[i] != separator && str[i + 1] == separator) {
            full_len[k] = i - next_index + 1;
            next_index = i + 2;
            k++;
        }
        i++;
    }
    return full_len;
}

char *word_saver(int indexes[], const char *str, int current_word_len,
char separator)
{
    int k = 0;
    char *word = malloc(sizeof(char) * (current_word_len + 1));

    while (indexes[1] <= indexes[0]) {
        word[k] = (str[indexes[1]] != separator) ? str[indexes[1]] : '\0';
        k = (str[indexes[1]] != separator) ? k + 1 : k;
        indexes[1]++;
    }
    word[k] = '\0';
    return (word);
}

char **divide_array(char const *str, int words_nb, char separator, int size)
{
    char **result = malloc(sizeof(char *) * (words_nb + 1));
    char *word;
    int *words_len = count_words_len(str, words_nb, separator, size);
    int current_word_len = 0;
    int l = 0;
    int indexes[] = {0, 0};

    for (indexes[0] = 0; indexes[0] < size; indexes[0]++) {
        current_word_len = words_len[l];
        if (str[indexes[0]] != separator && str[indexes[0] + 1] == separator) {
            word = word_saver(indexes, str, current_word_len, separator);
            indexes[1] = indexes[0] + 2;
            result[l++] = word;
        }
    }
    result[l] = NULL;
    free(words_len);
    return (result);
}

char **my_str_to_word_array(char const *str, char separator, int size)
{
    int words_nb = 0;
    char **result;

    for (int i = 0; i < size; i++)
        if (str[i] != separator && str[i + 1] == separator)
            words_nb++;
    result = divide_array(str, words_nb, separator, size);
    return (result);
}
