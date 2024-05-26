/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** giantman
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/giantman.h"

int main(int ac, char **av)
{
    char *str = NULL;
    int check_options = (av[2][0] != '1' && av[2][0] != '2' && av[2][0] != '3');

    if (ac != 3 || my_strlen(av[2]) > 1 || check_options)
        return (84);
    free(str);
    str = read_file(ac, av);
    if (error_gestion(ac, av, str) == 84 || str == NULL)
        return (84);
    if (av[2][0] == '1')
        if (texte_compression(ac, av, str) == 84)
            return (84);
    if (av[2][0] == '2')
        html_compression(ac, av, str);
    if (av[2][0] == '3')
        if (image_compression(ac, av, str) == 84)
            return (84);
    free(str);
    return (0);
}
