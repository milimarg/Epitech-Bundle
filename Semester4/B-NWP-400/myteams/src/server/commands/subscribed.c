/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** subscribed
*/

#include "server.h"

static size_t get_count(name_list_t *list)
{
    size_t count = 0;

    while (list) {
        list = list->next;
        ++count;
    }
    return count;
}

static void print_subscribed_users(client_t *client, team_t *team,
    server_t *server)
{
    client_t *tmp_user = NULL;
    int user_count = 0;

    if (!team)
        return;
    user_count = get_count(team->subscribed_clients);
    dprintf(client->fd, USERS, user_count);
    for (name_list_t *tmp = team->subscribed_clients; tmp; tmp = tmp->next) {
        tmp_user = check_if_uuid_existed(tmp->name, server);
        if (!tmp_user)
            continue;
        dprintf(client->fd, "\1UUID:%s, username:%s, status:%d\4",
            tmp_user->UUID, tmp_user->username, 1);
    }
    dprintf(client->fd, "]\r\n");
}

static void print_user_teams(client_t *client, server_t *server)
{
    team_t *tmp_team = NULL;
    long int team_count = 0;

    team_count = get_count(client->subscribed_teams);
    dprintf(client->fd, TEAMS, team_count);
    for (name_list_t *tmp = client->subscribed_teams; tmp; tmp = tmp->next) {
        tmp_team = find_team(server, tmp->name, true);
        if (!tmp_team)
            continue;
        dprintf(client->fd, "\1UUID:%s, name:%s, description:%s\4",
            tmp_team->team_uuid, tmp_team->name, tmp_team->description);
    }
    dprintf(client->fd, "]\r\n");
}

void subscribed(char *args, client_t *client, server_t *server)
{
    char *team_uuid = NULL;

    if (!client->is_identified) {
        dprintf(client->fd, NOT_LOGIN);
        return;
    }
    if (!args) {
        print_user_teams(client, server);
        return;
    }
    team_uuid = consume(args, "\"");
    if (team_uuid) {
        print_subscribed_users(client, find_team(server, team_uuid, true),
            server);
    } else {
        print_user_teams(client, server);
    }
}
