/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-mychannels-noe.tritsch
** File description:
** resp_203_channel_created_successfully
*/

#include "client.h"

static int get_channel_count(char *message, char **channels_start)
{
    int num_channels = 0;

    *channels_start = strstr(message, "channels (");
    if (!(*channels_start)) {
        dprintf(1, "Error: Channel count not found.\n");
        return -1;
    }
    if (sscanf(*channels_start, "channels (%d):", &num_channels) != 1) {
        dprintf(1, "Error: Failed to retrieve channel count.\n");
        return -1;
    }
    return num_channels;
}

static int scan_client(char *token, int channel_count)
{
    char uuid[MAX_UUID_LENGTH + 1] = {0};
    char name[MAX_NAME_LENGTH + 1] = {0};
    char description[MAX_DESCRIPTION_LENGTH + 1] = {0};

    if (sscanf(token, "UUID:%37[^,], name:%32[^,], description:%255[^\4]\4",
        uuid, name, description) == 3) {
        client_team_print_channels(uuid, name, description);
        ++channel_count;
    }
    return channel_count;
}

static void retrieve_channels(char *message, int num_channels)
{
    char *token = strtok(message, "\1");
    int channel_count = 0;

    while (token != NULL && channel_count < num_channels) {
        channel_count = scan_client(token, channel_count);
        token = strtok(NULL, "\1");
    }
}

void resp_212_list_channels(client_t *client, char *message)
{
    char *channels_start = NULL;
    int num_channels = get_channel_count(message, &channels_start);

    (void)client;
    if (num_channels == -1)
        return;
    retrieve_channels(channels_start, num_channels);
}
