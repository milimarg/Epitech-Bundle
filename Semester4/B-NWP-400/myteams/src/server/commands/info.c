/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** info
*/

#include "server.h"

void show_thread_info(client_t *client, server_t *server)
{
    team_t *team = find_team(server, client->team_uuid, true);
    channel_t *channel = find_channel(team, client->channel_uuid, true);
    thread_t *thread = find_thread(channel, client->thread_uuid, true);

    if (!team) {
        dprintf(client->fd, UNKNOW_TEAM, client->team_uuid);
        return;
    }
    if (!channel) {
        dprintf(client->fd, UNKNOW_CHANNEL, client->channel_uuid);
        return;
    }
    if (!thread) {
        dprintf(client->fd, UNKNOW_THREAD, client->channel_uuid);
        return;
    }
    dprintf(client->fd, THREAD, thread->thread_uuid,
    thread->author, thread->creation_date, thread->title, thread->message);
}

void show_channel_info(client_t *client, server_t *server)
{
    team_t *team = find_team(server, client->team_uuid, true);
    channel_t *channel = find_channel(team, client->channel_uuid, true);

    if (!team) {
        dprintf(client->fd, UNKNOW_TEAM, client->team_uuid);
        return;
    }
    if (!channel) {
        dprintf(client->fd, UNKNOW_CHANNEL, client->channel_uuid);
        return;
    }
    dprintf(client->fd, CHANNEL, channel->channel_uuid,
    channel->title, channel->description);
}

void show_team_info(client_t *client, server_t *server)
{
    team_t *team = find_team(server, client->team_uuid, true);

    if (!team) {
        dprintf(client->fd, UNKNOW_TEAM, client->team_uuid);
        return;
    }
    dprintf(client->fd, TEAM, team->team_uuid, team->name, team->description);
}

void show_user_info(client_t *client)
{
    dprintf(client->fd, USER, client->UUID, client->username,
    client->is_identified);
}

void handle_info(char *args, client_t *client, server_t *server)
{
    (void)args;
    if (!client->is_identified) {
        dprintf(client->fd, NOT_LOGIN);
        return;
    }
    if (!client->team_uuid)
        return show_user_info(client);
    if (!client->channel_uuid)
        return show_team_info(client, server);
    if (!client->thread_uuid)
        return show_channel_info(client, server);
    show_thread_info(client, server);
}
