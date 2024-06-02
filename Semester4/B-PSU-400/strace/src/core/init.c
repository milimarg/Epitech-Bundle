/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-strace-florent.guittre
** File description:
** init
*/

#include "../../include/strace.h"

bool handle_fork(strace_t *strace)
{
    strace->pid = fork();
    if (strace->pid == -1) {
        dprintf(2, "strace: fork failed: %s\n", strerror(errno));
        return true;
    }
    if (strace->pid == 0) {
        if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1) {
            dprintf(2, "strace: Operation not permitted\n");
            exit(1);
            return true;
        }
        execve(strace->abspath, strace->binary, strace->envp);
    }
    return false;
}

bool handle_attach(strace_t *strace)
{
    if (ptrace(PTRACE_ATTACH, strace->pid, NULL, NULL) == -1) {
        dprintf(2, "strace: Operation not permitted\n");
        return true;
    }
    dprintf(2, "strace: Process %d attached\n", strace->pid);
    return false;
}
