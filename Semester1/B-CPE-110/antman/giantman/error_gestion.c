/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** giantman
*/

#include <sys/stat.h>
#include "../include/my.h"
#include "../include/giantman.h"

int error_gestion(int ac, char **av, char *str)
{
    struct stat information;
    int error = stat(av[1], &information);

    if (error == -1)
        return (84);
    return (0);
}
