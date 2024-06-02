/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_203_team_created_successfully
*/

#include "client.h"

static int get_thread_count(char *message, char **threads_start)
{
    int num_threads = 0;

    *threads_start = strstr(message, "threads (");
    if (!(*threads_start)) {
        dprintf(1, "Error: Thread count not found.\n");
        return -1;
    }
    if (sscanf(*threads_start, "threads (%d):", &num_threads) != 1) {
        dprintf(1, "Error: Failed to retrieve thread count.\n");
        return -1;
    }
    return num_threads;
}

static int scan_client(char *token, int thread_count)
{
    char thread_uuid[MAX_UUID_LENGTH + 1] = {0};
    char user_uuid[MAX_UUID_LENGTH + 1] = {0};
    char thread_title[MAX_NAME_LENGTH + 1] = {0};
    char thread_body[MAX_BODY_LENGTH + 1] = {0};
    time_t timestamp = 0;

    if (sscanf(token, "[%37[^/]/%37[^/]/%ld/%32[^]]]: %512[^\4]\4",
        thread_uuid, user_uuid, &timestamp, thread_title, thread_body) == 5) {
        client_channel_print_threads(thread_uuid, user_uuid, timestamp,
            thread_title, thread_body);
        ++thread_count;
    }
    return thread_count;
}

static void retrieve_threads(char *message, int num_threads)
{
    char *token = strtok(message, "\1");
    int thread_count = 0;

    while (token != NULL && thread_count < num_threads) {
        thread_count = scan_client(token, thread_count);
        token = strtok(NULL, "\1");
    }
}

void resp_214_list_threads(client_t *client, char *message)
{
    char *threads_start = NULL;
    int num_threads = get_thread_count(message, &threads_start);

    (void)client;
    if (num_threads == -1)
        return;
    retrieve_threads(threads_start, num_threads);
}
