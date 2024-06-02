/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** NOOP_OK.c
*/

#include "../../include/include.h"

int noop(my_ftp *ftp __attribute_maybe_unused__,
    user_data *data, const char *value __attribute_maybe_unused__)
{
    dprintf(data->fd, NOOP_OK);
    return 0;
}
