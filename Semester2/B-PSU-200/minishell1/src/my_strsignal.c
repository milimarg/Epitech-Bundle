/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_strsignal
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../include/my.h"

int pid_signal_handler(sh_infos *shell, pid_t pid)
{
    int termsig_code = WTERMSIG(pid);
    int exitstatus_code = WEXITSTATUS(pid);
    int coredump = WCOREDUMP(pid);

    if (termsig_code > 0 && coredump == 0) {
        if (termsig_code == 8)
            write(2, "Floating exception\n", 19);
        if (termsig_code == 11)
            write(2, "Segmentation fault\n", 19);
        exitstatus_code = 128 + termsig_code;
    }
    if (termsig_code > 0 && coredump > 0) {
        if (termsig_code == 8)
            write(2, "Floating exception (core dumped)\n", 33);
        if (termsig_code == 11)
            write(2, "Segmentation fault (core dumped)\n", 33);
        exitstatus_code = 128 + termsig_code;
    }
    set_return_code(shell, exitstatus_code);
    return (0);
}
