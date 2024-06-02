/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** structs.h
*/

#ifndef B_NWP_400_STG_4_1_MYFTP_FLORENT_GUITTRE_STRUCTS_H
    #define B_NWP_400_STG_4_1_MYFTP_FLORENT_GUITTRE_STRUCTS_H

typedef struct {
    int port;
    int fd;
    int accept_fd;
    struct sockaddr_in addr;
} pasv_t;

typedef enum {
    NONE,
    PASSIVE,
    ACTIVE
} mode_type;

typedef struct {
    int fd;
    bool is_connected;
    bool is_auth;
    char *username;
    char *absolute_root;
    char *user_path; // relative
    char *server_path; // absolute
    bool is_cdup;
    pasv_t pasv;
    mode_type type;
} user_data;

typedef struct user_db_s {
    char *username;
    char *password;
    struct user_db_s *next;
} user_db;

typedef struct {
    int server_socket;
    fd_set readfds;
    struct sockaddr_in addr;
    user_data *data;
    int current_clients_number;
    size_t current_connected;
    user_db *users;
    char *trying_path;
    unsigned char ip[4];
} my_ftp;

#endif //B_NWP_400_STG_4_1_MYFTP_FLORENT_GUITTRE_STRUCTS_H
