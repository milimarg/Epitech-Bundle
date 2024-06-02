/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myserver-noe.tritsch
** File description:
** utils_2
*/

#include "server.h"

int count_char_number(char *str, char c)
{
    int i = 0;
    int count = 0;

    while (str && str[i]) {
        if (str[i] == c)
            count++;
        i++;
    }
    return count;
}

static bool is_empty(char *str)
{
    if (!str)
        return true;
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ' && str[i] != '\t')
            return false;
    return true;
}

char *consume(char *str, char *rejected)
{
    char *result = NULL;

    result = strtok(str, rejected);
    if (!is_empty(result))
        return result;
    return strtok(NULL, rejected);
}

int get_number_of_users(server_t *server)
{
    client_t *current = server->clients;
    int users_number = 0;

    while (current) {
        users_number++;
        current = current->next;
    }
    return users_number;
}
