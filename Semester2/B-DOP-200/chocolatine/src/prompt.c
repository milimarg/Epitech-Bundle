/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** prompt
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib/my/libmy.h"
#include "../include/my.h"

int display_prompt(sh_infos *shell)
{
    char buffer[1001] = {0};
    char *current_directory = getcwd(buffer, 1000);

    write(1, "(", 1);
    write(1, (shell->is_return_code_an_error) ? SRED : SGRN, 6);
    my_put_nbr(shell->return_code);
    write(1, SRST, 5);
    write(1, "):", 2);
    write(1, SPUR, 6);
    write(1, current_directory, my_strlen(current_directory));
    write(1, SRST, 5);
    write(1, "> ", 2);
    return (0);
}
