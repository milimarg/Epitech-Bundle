/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** create
*/

#include "server.h"

static replies_t *create_new_reply(client_t *client, char *comment_body,
    thread_t *thread)
{
    replies_t *replies = thread->replies;
    replies_t *reply = malloc(sizeof(replies_t));

    memset(reply, 0, sizeof(replies_t));
    strcpy(reply->author, client->UUID);
    strcpy(reply->message, comment_body);
    reply->creation_date = time(NULL);
    if (!thread->replies)
        thread->replies = reply;
    else {
        while (replies->next)
            replies = replies->next;
        replies->next = reply;
    }
    thread->replies_numbers++;
    dprintf(client->fd, REPLY_CREATED_SUCCESSFULLY, thread->thread_uuid,
    client->UUID, reply->creation_date, reply->message);
    return reply;
}

void create_reply(char *args, client_t *client, server_t *server,
    thread_t *thread)
{
    char *comment_body = NULL;
    replies_t *reply = NULL;
    team_t *team = find_team(server, client->team_uuid, true);
    client_t *current = NULL;

    (void)server;
    if (args == NULL || count_char_number(args, '\"') < 2) {
        dprintf(client->fd, SYNTAX_ERROR);
        return;
    }
    comment_body = consume(args, "\"");
    reply = create_new_reply(client, comment_body, thread);
    server_event_reply_created(thread->thread_uuid,
    client->UUID, reply->message);
    for (name_list_t *id = team->subscribed_clients; id; id = id->next) {
        current = check_if_uuid_existed(id->name, server);
        if (current && current->is_identified)
            dprintf(current->fd, THREAD_RECEIVED, team->team_uuid,
            thread->thread_uuid, client->UUID, reply->message);
    }
}

static thread_t *add_new_thread(channel_t *channel, client_t *client,
    thread_t *threads, thread_t *thread)
{
    if (!channel->threads)
        channel->threads = thread;
    else {
        while (threads->next)
            threads = threads->next;
        threads->next = thread;
    }
    dprintf(client->fd, THREAD_CREATED_SUCCESSFULLY, thread->thread_uuid,
    client->UUID, thread->creation_date, thread->title, thread->message);
    return thread;
}

static thread_t *create_new_thread(channel_t *channel, client_t *client,
    char *name, char *message)
{
    thread_t *threads = channel->threads;
    thread_t *thread = malloc(sizeof(thread_t));
    uuid_t uuid;

    memset(thread, 0, sizeof(thread_t));
    strcpy(thread->title, name);
    strcpy(thread->message, message);
    thread->creation_date = time(NULL);
    uuid_generate(uuid);
    uuid_unparse(uuid, thread->thread_uuid);
    strcpy(thread->author, client->channel_uuid);
    channel->threads_numbers++;
    return add_new_thread(channel, client, threads, thread);
}

void create_thread(char *args, client_t *client, server_t *server,
    channel_t *channel)
{
    char *thread_title = NULL;
    char *thread_message = NULL;
    thread_t *thread = NULL;

    if (args == NULL || count_char_number(args, '\"') < 4) {
        dprintf(client->fd, SYNTAX_ERROR);
        return;
    }
    thread_title = consume(args, "\"");
    thread_message = consume(NULL, "\"");
    if (find_thread(channel, thread_title, false)) {
        dprintf(client->fd, ERROR_UNAUTHORIZED);
        return;
    }
    thread = create_new_thread(channel, client, thread_title, thread_message);
    for (client_t *current = server->clients; current; current = current->next)
        dprintf(current->fd, THREAD_CREATED, thread->thread_uuid, client->UUID,
        thread->creation_date, thread->title, thread->message);
    server_event_thread_created(channel->channel_uuid,
    thread->thread_uuid, client->UUID, thread->title, thread->message);
}

static channel_t *create_new_channel(team_t *team, client_t *client,
    char *name, char *description)
{
    channel_t *channels = team->channels;
    channel_t *channel = malloc(sizeof(channel_t));
    uuid_t uuid;

    memset(channel, 0, sizeof(channel_t));
    strcpy(channel->title, name);
    strcpy(channel->description, description);
    uuid_generate(uuid);
    uuid_unparse(uuid, channel->channel_uuid);
    if (!team->channels)
        team->channels = channel;
    else {
        while (channels->next)
            channels = channels->next;
        channels->next = channel;
    }
    dprintf(client->fd, CHANNEL_CREATED_SUCCESSFULLY,
    channel->channel_uuid, channel->title, channel->description);
    team->channels_numbers++;
    return channel;
}

void create_channel(char *args, client_t *client, server_t *server,
    team_t *team)
{
    char *channel_name = NULL;
    char *channel_desc = NULL;
    channel_t *channel = NULL;

    if (args == NULL || count_char_number(args, '\"') < 4) {
        dprintf(client->fd, SYNTAX_ERROR);
        return;
    }
    channel_name = consume(args, "\"");
    channel_desc = consume(NULL, "\"");
    if (find_channel(team, channel_name, false)) {
        dprintf(client->fd, ERROR_UNAUTHORIZED);
        return;
    }
    channel = create_new_channel(team, client, channel_name, channel_desc);
    for (client_t *current = server->clients; current; current = current->next)
        dprintf(current->fd, CHANNEL_CREATED,
        channel->channel_uuid, channel->title, channel->description);
    server_event_channel_created(team->team_uuid,
    channel->channel_uuid, channel->title);
}

static team_t *create_new_team(server_t *server, client_t *client,
    char *name, char *description)
{
    team_t *teams = server->teams;
    team_t *team = malloc(sizeof(team_t));
    uuid_t uuid;

    memset(team, 0, sizeof(team_t));
    strcpy(team->name, name);
    strcpy(team->description, description);
    uuid_generate(uuid);
    uuid_unparse(uuid, team->team_uuid);
    if (!server->teams)
        server->teams = team;
    else {
        while (teams->next)
            teams = teams->next;
        teams->next = team;
    }
    dprintf(client->fd, TEAM_CREATED_SUCCESSFULLY,
    team->team_uuid, team->name, team->description);
    return team;
}

void create_team(char *args, client_t *client, server_t *server)
{
    char *team_name = NULL;
    char *team_description = NULL;
    team_t *team = NULL;

    if (args == NULL || count_char_number(args, '\"') < 4) {
        dprintf(client->fd, SYNTAX_ERROR);
        return;
    }
    team_name = consume(args, "\"");
    team_description = consume(NULL, "\"");
    if (find_team(server, team_name, false)) {
        dprintf(client->fd, ERROR_UNAUTHORIZED);
        return;
    }
    team = create_new_team(server, client, team_name, team_description);
    for (client_t *current = server->clients; current; current = current->next)
        dprintf(current->fd, TEAM_CREATED,
        team->team_uuid, team->name, team->description);
    server_event_team_created(team->team_uuid, team->name, client->UUID);
    server->teams_numbers++;
}

void handle_create(char *args, client_t *client, server_t *server)
{
    team_t *team = NULL;
    channel_t *channel = NULL;
    thread_t *thread = NULL;

    if (!client->is_identified) {
        dprintf(client->fd, NOT_LOGIN);
        return;
    }
    if (!client->team_uuid)
        return create_team(args, client, server);
    team = find_team(server, client->team_uuid, true);
    if (!client->channel_uuid)
        return create_channel(args, client, server, team);
    channel = find_channel(team, client->channel_uuid, true);
    if (!client->thread_uuid)
        return create_thread(args, client, server, channel);
    thread = find_thread(channel, client->thread_uuid, true);
    create_reply(args, client, server, thread);
}
