/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** user.c
*/

#include "../include/include.h"

void add_user(my_ftp *ftp, const char *login, const char *password)
{
    user_db *user = malloc(sizeof(user_db));

    user->username = strdup(login);
    user->password = strdup(password);
    user->next = ftp->users;
    ftp->users = user;
}

bool is_login_in_db(my_ftp *ftp, const char *login)
{
    for (user_db *temp = ftp->users; temp != NULL; temp = temp->next)
        if (!strcmp(temp->username, login))
            return true;
    return false;
}

char *get_password_by_login(my_ftp *ftp, const char *login)
{
    if (login == NULL)
        return NULL;
    for (user_db *temp = ftp->users; temp != NULL; temp = temp->next)
        if (temp->username && !strcmp(temp->username, login))
            return temp->password;
    return NULL;
}

void free_linked_list(user_db *users)
{
    user_db *to_delete = NULL;

    for (user_db *temp = users; temp != NULL;) {
        to_delete = temp;
        temp = temp->next;
        free(to_delete->username);
        free(to_delete->password);
        free(to_delete);
    }
}
