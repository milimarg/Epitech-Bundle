/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** subscribe
*/

#include "server.h"

static name_list_t *create_name_node(char *name)
{
    name_list_t *node = malloc(sizeof(name_list_t));

    if (node) {
        node->next = NULL;
        node->name = strdup(name);
    }
    return node;
}

static void append_name_node(name_list_t **head, name_list_t *new_node)
{
    name_list_t *tmp = NULL;

    if (!(*head)) {
        *head = new_node;
    } else {
        tmp = *head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_node;
    }
}

static void add_client_to_team(client_t *client, char *team_uuid, team_t *team)
{
    name_list_t *new_node_team = create_name_node(client->UUID);
    name_list_t *new_node_client = create_name_node(team_uuid);

    if (new_node_client && new_node_team) {
        append_name_node(&(client->subscribed_teams), new_node_client);
        append_name_node(&(team->subscribed_clients), new_node_team);
    } else {
        if (new_node_client) {
            free(new_node_client->name);
            free(new_node_client);
        }
        if (new_node_team) {
            free(new_node_team->name);
            free(new_node_team);
        }
    }
}

static bool is_already_subscribed(client_t *client, team_t *team)
{
    for (name_list_t *tmp = client->subscribed_teams; tmp; tmp = tmp->next)
        if (strcmp(tmp->name, team->team_uuid) == 0)
            return true;
    for (name_list_t *tmp = team->subscribed_clients; tmp; tmp = tmp->next)
        if (strcmp(tmp->name, client->UUID) == 0)
            return true;
    return false;
}

void subscribe(char *args, client_t *client, server_t *server)
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
    if (!team)
        return;
    if (is_already_subscribed(client, team))
        return;
    add_client_to_team(client, team_uuid, team);
    dprintf(client->fd, SUBSCRIBED, client->UUID, team->team_uuid);
}
