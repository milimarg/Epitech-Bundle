/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** use
*/

#include "server.h"

void reset_use(client_t *client)
{
    client->team_uuid = NULL;
    client->channel_uuid = NULL;
    client->thread_uuid = NULL;
}

static void check_other(client_t *client, team_t *team)
{
    channel_t *channel = NULL;

    client->channel_uuid = consume(NULL, "\"");
    if (client->channel_uuid) {
        client->channel_uuid = strdup(client->channel_uuid);
        channel = find_channel(team, client->channel_uuid, true);
        if (!channel) {
            dprintf(client->fd, UNKNOW_CHANNEL, client->channel_uuid);
            reset_use(client);
            return;
        }
    }
    client->thread_uuid = consume(NULL, "\"");
    if (client->thread_uuid) {
        client->thread_uuid = strdup(client->thread_uuid);
        if (!find_thread(channel, client->thread_uuid, true)) {
            dprintf(client->fd, UNKNOW_THREAD, client->thread_uuid);
            reset_use(client);
        }
    }
}

static bool check_base_case(client_t *client, char *args)
{
    if (!client->is_identified) {
        dprintf(client->fd, NOT_LOGIN);
        return true;
    }
    if (args == NULL) {
        reset_use(client);
        return true;
    }
    return false;
}

void use_command(char *args, client_t *client, server_t *server)
{
    team_t *team = NULL;

    if (check_base_case(client, args))
        return;
    if (count_char_number(args, '\"') % 2 != 0 ||
        count_char_number(args, '\"') == 0 ||
        count_char_number(args, '\"') > 6) {
        dprintf(client->fd, SYNTAX_ERROR);
        return;
    }
    client->team_uuid = strdup(consume(args, "\""));
    team = find_team(server, client->team_uuid, true);
    if (!team) {
        dprintf(client->fd, UNKNOW_TEAM, client->team_uuid);
        reset_use(client);
        return;
    }
    check_other(client, team);
}
