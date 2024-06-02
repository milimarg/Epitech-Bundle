/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** loop.h
*/

#ifndef B_NWP_400_STG_4_1_MYFTP_FLORENT_GUITTRE_LOOP_H
    #define B_NWP_400_STG_4_1_MYFTP_FLORENT_GUITTRE_LOOP_H

void set_socket_fds(my_ftp *ftp, int *max_socket);
int handle_accept(my_ftp *ftp);
int check_client_connection(my_ftp *ftp, user_data *data);
int loop(my_ftp *ftp);

#endif //B_NWP_400_STG_4_1_MYFTP_FLORENT_GUITTRE_LOOP_H
