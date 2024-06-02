/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** unsubscribe
*/

#include "server.h"

static void remove_node_from_list(name_list_t **head, char *name)
{
    name_list_t *tmp = *head;
    name_list_t *prev = NULL;

    while (tmp != NULL && strcmp(tmp->name, name) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    if (prev == NULL) {
        *head = tmp->next;
    } else {
        prev->next = tmp->next;
    }
    free(tmp->name);
    free(tmp);
}

static void remove_client_from_team(client_t *client, char *team_uuid,
    team_t *team)
{
    remove_node_from_list(&(client->subscribed_teams), team_uuid);
    remove_node_from_list(&(team->subscribed_clients), client->UUID);
}

void unsubscribe(char *args, client_t *client, server_t *server)
{
    char *team_uuid = NULL;
    team_t *team = NULL;

    if (!client->is_identified) {
        dprintf(client->fd, NOT_LOGIN);
        return;
    }
    if (args == NULL || count_char_number(args, '\"') < 2) {
        dprintf(client->fd, SYNTAX_ERROR);
        return;
    }
    team_uuid = consume(args, "\"");
    team = find_team(server, team_uuid, true);
    if (!team || !team->subscribed_clients || !client->subscribed_teams)
        return;
    remove_client_from_team(client, team_uuid, team);
    dprintf(client->fd, UNSUBSCRIBED, client->UUID, team->team_uuid);
}
