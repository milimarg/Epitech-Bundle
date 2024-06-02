/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-strace-florent.guittre
** File description:
** trace
*/

#include "../../include/strace.h"

int strace(strace_t *strace)
{
    core_strace_t *core = &strace->core;

    if (!strace->flag_p) {
        if (handle_fork(strace))
            return 84;
    } else {
        if (handle_attach(strace))
            return 84;
    }
    core_strace(strace, core);
    ptrace(PTRACE_DETACH, strace->pid, NULL, NULL);
    strace_print("+++ exited with 0 +++\n", 22);
    return 0;
}
