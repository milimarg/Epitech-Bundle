/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** list
*/

#include "server.h"

void show_replies_list(client_t *client, server_t *server)
{
    team_t *team = find_team(server, client->team_uuid, true);
    channel_t *channel = find_channel(team, client->channel_uuid, true);
    thread_t *thread = find_thread(channel, client->thread_uuid, true);
    replies_t *replies = NULL;

    if (!thread) {
        dprintf(client->fd, UNKNOW_THREAD, client->thread_uuid);
    } else {
        replies = thread->replies;
        dprintf(client->fd, REPLIES, channel->threads_numbers);
        while (replies) {
            dprintf(client->fd, "\1[%s/%s/%ld]: %s\4",
            thread->thread_uuid,
            client->UUID, replies->creation_date, replies->message);
            replies = replies->next;
        }
        dprintf(client->fd, "]\r\n");
    }
}

void show_threads_list(client_t *client, server_t *server)
{
    team_t *team = find_team(server, client->team_uuid, true);
    channel_t *channel = find_channel(team, client->channel_uuid, true);
    thread_t *threads = NULL;

    if (!channel) {
        dprintf(client->fd, UNKNOW_CHANNEL, client->channel_uuid);
    } else {
        threads = channel->threads;
        dprintf(client->fd, THREADS, channel->threads_numbers);
        while (threads) {
            dprintf(client->fd, "\1[%s/%s/%ld/%s]: %s\4",
            threads->thread_uuid, threads->author, threads->creation_date,
            threads->title, threads->message);
            threads = threads->next;
        }
        dprintf(client->fd, "]\r\n");
    }
}

void show_channels_list(client_t *client, server_t *server)
{
    team_t *team = find_team(server, client->team_uuid, true);
    channel_t *channels = NULL;

    if (!team) {
        dprintf(client->fd, UNKNOW_TEAM, client->team_uuid);
    } else {
        channels = team->channels;
        dprintf(client->fd, CHANNELS, team->channels_numbers);
        while (channels) {
            dprintf(client->fd, "\1UUID:%s, name:%s, description:%s\4",
            channels->channel_uuid, channels->title, channels->description);
            channels = channels->next;
        }
        dprintf(client->fd, "]\r\n");
    }
}

void show_teams_list(client_t *client, server_t *server)
{
    team_t *teams = server->teams;

    dprintf(client->fd, TEAMS, server->teams_numbers);
    while (teams) {
        dprintf(client->fd, "\1UUID:%s, name:%s, description:%s\4",
        teams->team_uuid, teams->name, teams->description);
        teams = teams->next;
    }
    dprintf(client->fd, "]\r\n");
}

void handle_list(char *args, client_t *client, server_t *server)
{
    (void)args;
    if (!client->is_identified) {
        dprintf(client->fd, NOT_LOGIN);
        return;
    }
    if (!client->team_uuid)
        return show_teams_list(client, server);
    if (!client->channel_uuid)
        return show_channels_list(client, server);
    if (!client->thread_uuid)
        return show_threads_list(client, server);
    show_replies_list(client, server);
}
