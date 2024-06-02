/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_106_users
*/

#include "client.h"

static bool get_user_count(client_t *client, char *message, char **users_start)
{
    int num_users = 0;

    *users_start = strstr(message, "users (");
    if (!(*users_start)) {
        dprintf(1, "Error: User count not found.\n");
        return false;
    }
    if (sscanf(*users_start, "users (%d):", &num_users) != 1) {
        dprintf(1, "Error: Failed to retrieve user count.\n");
        return false;
    }
    client->num_users = num_users;
    return true;
}

static int scan_client(client_t *client, char *token, int user_count)
{
    char uuid[MAX_UUID_LENGTH + 1] = {0};
    char username[MAX_NAME_LENGTH + 1] = {0};
    int status = 0;

    if (sscanf(token, "UUID:%37[^,], username:%32[^,], status:%d\4",
        uuid, username, &status) == 3) {
        snprintf(client->users[user_count].uuid,
            sizeof(client->users[user_count].uuid), "%s", uuid);
        snprintf(client->users[user_count].username,
            sizeof(client->users[user_count].username), "%s", username);
        client->users[user_count].status = status;
        ++user_count;
    }
    return user_count;
}

static void retrieve_users(client_t *client, char *message)
{
    char *token = strtok(message, "\1");
    int user_count = 0;

    while (token != NULL && user_count < client->num_users) {
        user_count = scan_client(client, token, user_count);
        token = strtok(NULL, "\1");
    }
}

void resp_208_list_users(client_t *client, char *message)
{
    char *users_start = NULL;

    if (!get_user_count(client, message, &users_start))
        return;
    retrieve_users(client, users_start);
    for (int i = 0; i < client->num_users; ++i) {
        client_print_users(client->users[i].uuid, client->users[i].username,
            client->users[i].status);
    }
}
