/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** server_utils
*/

#include "server.h"

thread_t *find_thread(channel_t *channel, char *name, bool is_uuid)
{
    thread_t *threads = channel->threads;
    char *to_compare = NULL;

    while (threads) {
        if (is_uuid)
            to_compare = threads->thread_uuid;
        else
            to_compare = threads->title;
        if (strcmp(to_compare, name) == 0)
            return threads;
        threads = threads->next;
    }
    return NULL;
}

channel_t *find_channel(team_t *team, char *name, bool is_uuid)
{
    channel_t *channels = team->channels;
    char *to_compare = NULL;

    while (channels) {
        if (is_uuid)
            to_compare = channels->channel_uuid;
        else
            to_compare = channels->title;
        if (strcmp(to_compare, name) == 0)
            return channels;
        channels = channels->next;
    }
    return NULL;
}

team_t *find_team(server_t *server, char *name, bool is_uuid)
{
    team_t *teams = server->teams;
    char *to_compare = NULL;

    while (teams) {
        if (is_uuid)
            to_compare = teams->team_uuid;
        else
            to_compare = teams->name;
        if (strcmp(to_compare, name) == 0)
            return teams;
        teams = teams->next;
    }
    return NULL;
}
