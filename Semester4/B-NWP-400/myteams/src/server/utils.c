/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myserver-noe.tritsch
** File description:
** utils
*/

#include "server.h"

int tab_len(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return i;
}

int last_occurence_of(char c, char *str)
{
    int last = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            last = i;
    }
    return last;
}

static bool is_rejected(char c, char *reject)
{
    for (int i = 0; reject[i]; i++)
        if (reject[i] == c)
            return true;
    return false;
}

int count_my_words(char *str, char *reject)
{
    int nb = 0;
    bool previous_was_space = true;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_rejected(str[i], reject) && previous_was_space) {
            nb++;
            previous_was_space = false;
            continue;
        }
        if (is_rejected(str[i], reject)) {
            previous_was_space = true;
            continue;
        }
    }
    return nb;
}

char **split_my_args(char *str, char *rejected)
{
    int words = count_my_words(str, rejected);
    char **args = NULL;
    char *token = NULL;
    int i = 0;

    if (words == 0) {
        return NULL;
    }
    args = malloc(sizeof(char *) * (words + 1));
    token = strtok(str, rejected);
    while (token) {
        args[i] = strdup(token);
        token = strtok(NULL, rejected);
        i++;
    }
    args[words] = NULL;
    return args;
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
