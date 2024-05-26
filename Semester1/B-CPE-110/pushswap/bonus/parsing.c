/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** parsing
*/

#include <stdlib.h>
#include "include/my_struct.h"
#include "include/my.h"

int *get_args(int argc, char *argv[])
{
    int args_nb = 3;
    char *args_list[] = {"-v", "-vT", "-vG"};
    int *args = malloc(sizeof(int) * args_nb);

    if (argc >= 2) {
        for (int i = 0; i < args_nb; i++) {
            args[i] = (!my_strcmp(argv[1], args_list[i]) && !args[i]);
        }
    }
    return (args);
}
