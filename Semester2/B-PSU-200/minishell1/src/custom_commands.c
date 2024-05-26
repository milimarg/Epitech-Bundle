/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** custom_commands
*/

#include <stdlib.h>
#include "../include/my.h"

static int add_custom_command(custom_commands **commands_list, char *command,
int (*func)(sh_infos *shell, my_env **env_list))
{
    custom_commands *element = malloc(sizeof(custom_commands));

    element->command = command;
    element->func = func;
    element->next = *commands_list;
    *commands_list = element;
    return (0);
}

int destroy_custom_commands_list(custom_commands *commands_list)
{
    custom_commands *temp = NULL;

    while (commands_list != NULL) {
        temp = commands_list;
        commands_list = commands_list->next;
        free(temp);
    }
    return (0);
}

int init_custom_commands(custom_commands **commands_list)
{
    add_custom_command(commands_list, "cd", &custom_cd);
    add_custom_command(commands_list, "setenv", &custom_setenv);
    add_custom_command(commands_list, "unsetenv", &custom_unsetenv);
    add_custom_command(commands_list, "env", &custom_env);
    add_custom_command(commands_list, "exit", &custom_exit);
    return (0);
}
