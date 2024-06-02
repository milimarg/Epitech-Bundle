/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_202_all_messages
*/

#include "client.h"

static char *get_start_info(char *message)
{
    char uuid[MAX_UUID_LENGTH + 1] = {0};
    char *remaining = NULL;
    int uuid_length = 0;
    int remaining_length = 0;

    if (!message) {
        dprintf(1, "Error: start info not found.\n");
        return NULL;
    }
    if (sscanf(message, "Here are all the messages with %37[^:]: [%n",
        uuid, &uuid_length) != 1) {
        dprintf(1, "Error: Failed to retrieve start info.\n");
        return NULL;
    }
    remaining_length = strlen(message + uuid_length);
    remaining = malloc(remaining_length + 1);
    memset(remaining, 0, remaining_length);
    strcpy(remaining, message + uuid_length);
    return remaining;
}

static void retrieve_message_info(char *token)
{
    char uuid[MAX_UUID_LENGTH + 1] = {0};
    char body[MAX_BODY_LENGTH + 1] = {0};
    time_t timestamp = 0;

    if (sscanf(token,
        "UUID:%37[^,], timestamp:%ld, messages: %512[^\4]\4",
        uuid, &timestamp, body) == 3) {
        client_private_message_print_messages(uuid, timestamp, body);
    }
}

static void retrieve_messages(char *message)
{
    char *token = strtok(message, "\1");

    while (token != NULL) {
        retrieve_message_info(token);
        token = strtok(NULL, "\1");
    }
}

void resp_216_list_messages(client_t *client, char *message)
{
    char *remaining = NULL;

    (void)client;
    remaining = get_start_info(message);
    if (!remaining)
        return;
    retrieve_messages(remaining);
    free(remaining);
}
