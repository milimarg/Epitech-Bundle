/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** user.h
*/

#ifndef B_NWP_400_STG_4_1_MYFTP_FLORENT_GUITTRE_USER_H
    #define B_NWP_400_STG_4_1_MYFTP_FLORENT_GUITTRE_USER_H

void add_user(my_ftp *ftp, const char *login, const char *password);
bool is_login_in_db(my_ftp *ftp, const char *login);
char *get_password_by_login(my_ftp *ftp, const char *login);
void free_linked_list(user_db *users);

#endif //B_NWP_400_STG_4_1_MYFTP_FLORENT_GUITTRE_USER_H
