/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** custom_lib
*/

#include <signal.h>
#include <stdlib.h>
#include "lib/my/libmy.h"
#include "../include/my.h"

int get_alphanum_len(char *str)
{
    int variable_len = 0;

    for (; my_char_isvisiblenum(*(str + variable_len)); variable_len++);
    return (variable_len);
}

int my_array_len(char **array)
{
    char **s = array;

    for (; *array; array++);
    return (array - s);
}

int check_if_buffer_is_alpha(sh_infos *shell)
{
    for (int i = 0; shell->current_command[i] &&
    shell->current_command[i + 1] != '\0'; i++) {
        if (my_char_isvisible(shell->current_command[i]))
            return (1);
    }
    return (0);
}

int check_if_malloc_is_null(void)
{
    char *malloc_checker = malloc(sizeof(char));
    int is_null = (malloc_checker == NULL);

    free(malloc_checker);
    return (is_null);
}
