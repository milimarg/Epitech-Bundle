/*
** EPITECH PROJECT, 2024
** bootstrap_server
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_
    #include "messages.h"
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <string.h>
    #include <stdio.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/select.h>
    #include <stdbool.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <fcntl.h>
    #include <time.h>
    #include "../libs/myteams/logging_server.h"
    #include <uuid/uuid.h>

    #define BACKLOG 5
    #define MAX_BUFFER 4096
    #define MAX_CLIENTS 50
    #define MAX_NAME_LENGTH 32
    #define MAX_UUID_LENGTH 37
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

typedef struct messages_s {
    char *sender_uuid;
    char *receiver_uuid;
    char *message;
    time_t timestamp;
    struct messages_s *next;
} messages_t;

typedef struct name_list_s {
    char *name;
    struct name_list_s *next;
} name_list_t;


typedef struct client_s {
    int fd;
    bool is_identified;
    char username[MAX_NAME_LENGTH];
    char UUID[MAX_UUID_LENGTH];
    // BUFFER MANAGEMENT
    bool need_to_write;
    char command[MAX_BUFFER];
    size_t connected_users;
    // USE COMMAND
    char *team_uuid;
    char *channel_uuid;
    char *thread_uuid;
    // CLIENT LIST
    struct client_s *next;
    // TEAMS
    name_list_t *subscribed_teams;
} client_t;

typedef struct replies_s {
    char author[MAX_BODY_LENGTH];
    time_t creation_date;
    char message[MAX_BODY_LENGTH];
    struct replies_s *next;
} replies_t;

typedef struct thread_s {
    char author[MAX_BODY_LENGTH];
    char thread_uuid[MAX_UUID_LENGTH];
    time_t creation_date;
    char title[MAX_DESCRIPTION_LENGTH];
    char message[MAX_BODY_LENGTH];
    replies_t *replies;
    size_t replies_numbers;
    struct thread_s *next;
} thread_t;

typedef struct channel_s {
    char title[MAX_NAME_LENGTH];
    char channel_uuid[MAX_UUID_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct thread_s *threads;
    size_t threads_numbers;
    struct channel_s *next;
} channel_t;

typedef struct team_s {
    char name[MAX_NAME_LENGTH];
    char team_uuid[MAX_UUID_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct channel_s *channels;
    size_t channels_numbers;
    struct team_s *next;
    // CLIENTS
    name_list_t *subscribed_clients;
} team_t;

typedef struct {
    int PORT;
    int serv_socket;
    struct sockaddr_in adress;
    int len;
    int opt;
    //
    int new_socket;
    client_t *clients;
    fd_set readfds;
    fd_set writefds;
    //
    bool client_disconnect;
    team_t *teams;
    size_t teams_numbers;
    messages_t *messages;
} server_t;

bool setup_socket(server_t *server, char *port);
bool setup_server(server_t *server);
void add_user(server_t *server, client_t *client);

void loop_server(server_t *server);

bool get_activity(server_t *server);
void get_client_input(server_t *server);
bool add_client(server_t *server);

void free_all(server_t *server);

// UTILS
int last_occurence_of(char c, char *str);
int tab_len(char **tab);
int count_my_words(char *str, char *reject);
char **split_my_args(char *str, char *rejected);
void free_tab(char **tab);
int count_char_number(char *str, char c);
char *consume(char *str, char *rejected);
int get_number_of_users(server_t *server);
thread_t *find_thread(channel_t *channel, char *name, bool is_uuid);
channel_t *find_channel(team_t *team, char *name, bool is_uuid);
team_t *find_team(server_t *server, char *name, bool is_uuid);

// COMMANDS
void handle_commands(char *command, char *substring,
    client_t *client, server_t *server);
void handle_login(char *args, client_t *client, server_t *server);
void get_help(char *args, client_t *client, server_t *server);
void handle_logout(char *args, client_t *client, server_t *server);
client_t *check_if_uuid_existed(char *UUID, server_t *server);
char *check_if_username_existed(char *username, server_t *server);
void show_users(char *args, client_t *client, server_t *server);
void get_user(char *args, client_t *client, server_t *server);
void send_message(char *args, client_t *client, server_t *server);
void show_messages(char *args, client_t *client, server_t *server);
void use_command(char *args, client_t *client, server_t *server);
void handle_list(char *args, client_t *client, server_t *server);
void handle_info(char *args, client_t *client, server_t *server);
void handle_create(char *args, client_t *client, server_t *server);
void subscribe(char *args, client_t *client, server_t *server);
void unsubscribe(char *args, client_t *client, server_t *server);
void subscribed(char *args, client_t *client, server_t *server);
void create_reply(char *args, client_t *client, server_t *server,
    thread_t *threads);

void write_user_in_file(client_t *client);


#endif /* !SERVER_H_ */
// ! TODO
// ? ALREADY DID
//
// ? • /help : show help
// ? • /login [user_name] : set the user_name used by client
// ? • /logout : disconnect the client from the server
// ? • /users : get the list of all users that exist on the domain
// ? • /user [user_uuid] : get details about the requested user
// ? • /send [user_uuid] [message_body] : send a message to specific user
// ? • /messages [user_uuid] : list all messages exchanged with the specified
// ? user
// ? • /subscribe [team_uuid] : subscribe to the events of a team and its
// ? sub directories (enable reception
// ? of all events from a team)
// ? • /subscribed ?[team_uuid] : list all subscribed teams or list all
// ? users subscribed to a team
// ? • /unsubscribe [team_uuid] : unsubscribe from a team
// ? • /use ?[team_uuid] ?[channel_uuid] ?[thread_uuid] : Sets the
// ? command context to a team/channel/thread
// ? • /create : based on the context, create the sub resource (see below)
// ? • /list : based on the context, list all the sub resources (see below)
// ? • /info : based on the context, display details of the current resource
// ? (see below)
