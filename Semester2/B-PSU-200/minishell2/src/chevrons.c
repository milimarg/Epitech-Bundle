/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-florent.guittre
** File description:
** chevrons.c
*/

#include <stdlib.h>
#include "lib/my/libmy.h"
#include "../include/my.h"

void check_chevrons(char *command_string, sh_infos *shell)
{
    for (int i = 0; command_string[i] != '\0'; i++) {
        if (command_string[i] == '>' && command_string[i + 1] != '>') {
            shell->red->type = STDOUT;
            return;
        }
        if (command_string[i] == '>' && command_string[i + 1] == '>') {
            shell->red->type = STDOUT_APPEND;
            return;
        }
        if (command_string[i] == '<' && command_string[i + 1] != '<') {
            shell->red->type = STDIN;
            return;
        }
        if (command_string[i] == '<' && command_string[i + 1] == '<') {
            shell->red->type = STDIN_APPEND;
            return;
        }
    }
    shell->red->type = -1;
}

void handle_chevrons(char *command_string, redirection *red)
{
    int i = 0;
    char char_to_check = 0;

    if (red->type == STDOUT || red->type == STDOUT_APPEND)
        char_to_check = '>';
    else
        char_to_check = '<';
    for (; command_string[i] != char_to_check; i++);
    red->command = malloc(sizeof(char) * (i + 1));
    red->command[i] = 0;
    red->command = my_strncpy(red->command, command_string, i);
    red->commands_args_left = my_str_to_word_array(red->command);
    i++;
    if (red->type == STDOUT_APPEND || red->type == STDIN_APPEND)
        i++;
    red->commands_args_right = my_str_to_word_array(&command_string[i]);
}
