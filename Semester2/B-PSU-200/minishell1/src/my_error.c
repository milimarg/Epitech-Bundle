/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** myerror
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "lib/my/libmy.h"
#include "../include/my.h"

int set_return_code(sh_infos *shell, int return_code)
{
    if (shell->return_code != return_code)
        shell->return_code = return_code;
    shell->is_return_code_an_error = (return_code != 0);
    return (0);
}

int my_error(char *path, unsigned int mode_index)
{
    unsigned int modes_len = 12;
    char *modes[] = {"No such file or directory.\n", "Command not found.\n",
    "Undefined variable.\n", "Expression Syntax.\n", "Badly formed number.\n",
    "Too many arguments.\n", "Too few arguments.\n",
    "Variable name must contain alphanumeric characters.\n",
    "Permission denied.\n", "Variable name must begin with a letter.\n",
    "Not a directory.\n", "Exec format error. Wrong Architecture.\n"};
    int modes_type[] = {27, 19, 20, 19, 21, 20, 19, 52, 19, 40, 17, 39};

    if (mode_index >= modes_len)
        return (1);
    write(2, path, my_strlen(path));
    write(2, ": ", 2);
    write(2, modes[mode_index], modes_type[mode_index]);
    return (0);
}
