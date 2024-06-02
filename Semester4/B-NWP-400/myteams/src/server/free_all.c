/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myserver-noe.tritsch
** File description:
** free_all
*/

#include "server.h"

static void free_replies(replies_t *replies)
{
    replies_t *prev = NULL;

    while (replies) {
        prev = replies;
        replies = replies->next;
        free(prev);
    }
}

static void free_threads(thread_t *threads)
{
    thread_t *prev = NULL;

    while (threads) {
        prev = threads;
        threads = threads->next;
        free_replies(prev->replies);
        free(prev);
    }
}

static void free_channels(channel_t *channels)
{
    channel_t *prev = NULL;

    while (channels) {
        prev = channels;
        channels = channels->next;
        free_threads(prev->threads);
        free(prev);
    }
}

static void free_teams(team_t *teams)
{
    team_t *prev = NULL;

    while (teams) {
        prev = teams;
        teams = teams->next;
        free_channels(prev->channels);
        free(prev);
    }
}

static void free_clients(client_t *clients)
{
    client_t *prev = NULL;

    while (clients) {
        if (prev) {
            free(prev);
            prev = NULL;
        }
        prev = clients;
        clients = clients->next;
    }
    if (prev)
        free(prev);
}

void free_all(server_t *server)
{
    if (server) {
        close(server->serv_socket);
        free_clients(server->clients);
        free_teams(server->teams);
        free(server);
    }
}
