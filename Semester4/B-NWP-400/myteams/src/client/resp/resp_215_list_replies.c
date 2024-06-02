/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_203_team_created_successfully
*/

#include "client.h"

static int get_reply_count(char *message, char **replies_start)
{
    int num_reply = 0;

    *replies_start = strstr(message, "replies (");
    if (!(*replies_start)) {
        dprintf(1, "Error: Reply count not found.\n");
        return -1;
    }
    if (sscanf(*replies_start, "replies (%d):", &num_reply) != 1) {
        dprintf(1, "Error: Failed to retrieve replies count.\n");
        return -1;
    }
    return num_reply;
}

static int scan_client(char *token, int reply_count)
{
    char thread_uuid[MAX_UUID_LENGTH + 1] = {0};
    char user_uuid[MAX_UUID_LENGTH + 1] = {0};
    char reply_body[MAX_BODY_LENGTH + 1] = {0};
    time_t timestamp = 0;

    if (sscanf(token, "[%37[^/]/%37[^/]/%ld]: %512[^\4]\4",
        thread_uuid, user_uuid, &timestamp, reply_body) == 5) {
        client_thread_print_replies(thread_uuid, user_uuid, timestamp,
            reply_body);
        ++reply_count;
    }
    return reply_count;
}

static void retrieve_replies(char *message, int num_reply)
{
    char *token = strtok(message, "\1");
    int reply_count = 0;

    while (token != NULL && reply_count < num_reply) {
        reply_count = scan_client(token, reply_count);
        token = strtok(NULL, "\1");
    }
}

void resp_215_list_replies(client_t *client, char *message)
{
    char *replies_start = NULL;
    int num_reply = get_reply_count(message, &replies_start);

    (void)client;
    if (num_reply == -1)
        return;
    retrieve_replies(replies_start, num_reply);
}
