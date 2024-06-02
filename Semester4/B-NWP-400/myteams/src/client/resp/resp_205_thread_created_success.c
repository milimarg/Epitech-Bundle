/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_203_team_created_successfully
*/

#include "client.h"

void resp_205_thread_created_successfully(client_t *client, char *message)
{
    char thread_uuid[MAX_UUID_LENGTH + 1] = {0};
    char user_uuid[MAX_UUID_LENGTH + 1] = {0};
    char thread_title[MAX_NAME_LENGTH + 1] = {0};
    char thread_body[MAX_BODY_LENGTH + 1] = {0};
    time_t timestamp = 0;

    (void)client;
    if (sscanf(message, "[%37[^/]/%37[^/]/%ld/%32[^]]]: %512[^\4]\4",
        thread_uuid, user_uuid, &timestamp, thread_title, thread_body) == 5) {
        client_print_thread_created(thread_uuid, user_uuid, timestamp,
            thread_title, thread_body);
    } else {
        dprintf(1, "Error while retrieving the received message\n");
    }
}
