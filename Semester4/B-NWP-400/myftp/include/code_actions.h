/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** code_actions.h
*/

#ifndef B_NWP_400_STG_4_1_MYFTP_FLORENT_GUITTRE_CODE_ACTIONS_H
    #define B_NWP_400_STG_4_1_MYFTP_FLORENT_GUITTRE_CODE_ACTIONS_H

int connection_establishment(user_data *data);

int dummy(my_ftp *ftp, user_data *data, const char *value);
int login(my_ftp *ftp, user_data *data, const char *value);
int pass(my_ftp *ftp, user_data *data, const char *value);
int cdup(my_ftp *ftp, user_data *data, const char *value);
int pwd(my_ftp *ftp, user_data *data, const char *value);
int noop(my_ftp *ftp, user_data *data, const char *value);
int help(my_ftp *ftp, user_data *data, const char *value);
int quit(my_ftp *ftp, user_data *data, const char *value);
int pasv(my_ftp *ftp, user_data *data, const char *value);
int list(my_ftp *ftp, user_data *data, const char *value);
int dele(my_ftp *ftp, user_data *data, const char *value);
int retr(my_ftp *ftp, user_data *data, const char *value);

int cwd(my_ftp *ftp, user_data *data, const char *value);
char *get_new_user_path(user_data *data, char *given_directory);

#endif //B_NWP_400_STG_4_1_MYFTP_FLORENT_GUITTRE_CODE_ACTIONS_H
