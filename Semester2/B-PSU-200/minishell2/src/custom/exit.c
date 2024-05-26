/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** exit
*/

#include <sys/types.h>
#include <unistd.h>
#include "../lib/my/libmy.h"
#include "../../include/my.h"

static int exit_status_checker(sh_infos *shell)
{
    int has_found_digits = 0;

    for (int i = 0; shell->args[1][i] != '\0'; i++) {
        if (my_char_isnum(shell->args[1][i]))
            has_found_digits = 1;
        if (!my_char_isnum(shell->args[1][i]) && !has_found_digits) {
            my_error("exit", 3);
            set_return_code(shell, 1);
            return (1);
        }
        if ((!my_char_isnum(shell->args[1][i]) && has_found_digits) ||
        (shell->args[1][i] == '-' && shell->args[1][i + 1] == '-')) {
            my_error("exit", 4);
            set_return_code(shell, 1);
            return (1);
        }
    }
    return (0);
}

int custom_exit(sh_infos *shell, my_env **env_list)
{
    int status = 0;

    if (shell->args[1] != NULL) {
        status = exit_status_checker(shell);
        if (status != 0)
            return (status);
        set_return_code(shell, (unsigned char)my_getnbr(shell->args[1]));
    }
    if (isatty(0))
        write(1, "exit\n", 5);
    return (442);
}
