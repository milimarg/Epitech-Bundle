/*
** EPITECH PROJECT, 2022
** CPOOL_Day08
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>

void my_strlen(char const *str);

int my_char_isalpha(char const c);

int *count_words_len(char const *str, int words_nb)
{
    int i;
    int k;
    int next_index;
    int *full_len;

    i = 0;
    k = 0;
    next_index = 0;
    full_len = malloc(sizeof(int) * words_nb);
    while (str[i] != '\0') {
        if (my_char_isalpha(str[i]) && !my_char_isalpha(str[i + 1])) {
            full_len[k] = i - next_index + 1;
            next_index = i + 2;
            k++;
        }
        i++;
    }
    return full_len;
}

char *word_saver(int i, int j, const char *str, int current_word_len)
{
    int k;
    char *word;

    k = 0;
    word = malloc(sizeof(char) * (current_word_len + 1));
    while (j <= i) {
        word[k] = (my_char_isalpha(str[j])) ? str[j] : '\0';
        k = (my_char_isalpha(str[j])) ? k + 1 : k;
        j++;
    }
    word[k] = '\0';
    return word;
}

char **divide_array(char const *str, int words_nb)
{
    char **result;
    char *word;
    int *words_len;
    int current_word_len;
    int j;
    int l;

    l = 0;
    words_len = count_words_len(str, words_nb);
    result = malloc(sizeof(char *) * words_nb + 1);
    for (int i = 0; str[i] != '\0'; i++) {
        current_word_len = words_len[l];
        if (my_char_isalpha(str[i]) && !my_char_isalpha(str[i + 1])) {
            word = word_saver(i, j, str, current_word_len);
            j = i + 2;
            result[l++] = word;
        }
    }
    result[l] = NULL;
    return result;
}

char **my_str_to_word_array(char const *str)
{
    int words_nb;
    char **result;

    words_nb = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (my_char_isalpha(str[i]) && !my_char_isalpha(str[i + 1]))
            words_nb++;
    result = divide_array(str, words_nb);
    return result;
}
