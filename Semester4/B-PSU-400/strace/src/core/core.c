/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-strace-florent.guittre
** File description:
** core
*/

#include "../../include/strace.h"

static bool check_if_quit(strace_t *strace __attribute_maybe_unused__,
    core_strace_t *core)
{
    return WIFEXITED(core->status) || WIFSTOPPED(core->status);
}

static char *create_buffer(int buffer_size)
{
    char *buffer = malloc(sizeof(char) * buffer_size);

    if (!buffer)
        exit(84);
    return buffer;
}

static void syscall_args(strace_t *strace, core_strace_t *core, int *offset,
    int i)
{
    for (int j = 0; j < table[i].nb_args; j++) {
        store_display(strace, offset, core->registers[j], j);
        if (j < table[i].nb_args - 1)
            *offset += sprintf(core->buffer + *offset, ", ");
    }
}

static void syscall_return(strace_t *strace, core_strace_t *core, int *offset)
{
    ptrace(PTRACE_SINGLESTEP, strace->pid, NULL, NULL);
    waitpid(strace->pid, &core->status, 0);
    ptrace(PTRACE_GETREGS, strace->pid, NULL, &core->regs);
    if (core->regs.orig_rax == 60 || core->regs.orig_rax == 231)
        *offset += sprintf(core->buffer + *offset, "?");
    else
        store_display(strace, offset, core->regs.rax, -1);
    *offset += sprintf(core->buffer + *offset, "\n");
}

static void handle_buffer_overflow(core_strace_t *core, int *offset,
    int *buffer_size)
{
    char *newBuffer = NULL;

    if (*offset > *buffer_size - 100) {
        *buffer_size *= 2;
        newBuffer = realloc(core->buffer, *buffer_size);
        if (!newBuffer) {
            free(core->buffer);
            exit(84);
        }
        core->buffer = newBuffer;
    }
}

static void core_tracer(strace_t *strace, core_strace_t *core, int *offset,
    int *buffer_size)
{
    for (int i = 0; table[i].nb != -1; i++) {
        if ((int)(core->regs.orig_rax) == table[i].nb) {
            strace->rdx = i;
            store_args(core->args, table[i]);
            *offset += sprintf(core->buffer + *offset, "%s(", table[i].name);
            syscall_args(strace, core, offset, i);
            *offset += sprintf(core->buffer + *offset, ") = ");
            syscall_return(strace, core, offset);
            handle_buffer_overflow(core, offset, buffer_size);
        }
    }
}

static void tracer(strace_t *strace, core_strace_t *core)
{
    int offset = 0;
    int buffer_size = 1024;

    ptrace(PTRACE_GETREGS, strace->pid, NULL, &core->regs);
    store_registers(core->registers, &core->regs);
    strace->core.buffer = create_buffer(buffer_size);
    core_tracer(strace, core, &offset, &buffer_size);
    strace_print(core->buffer, offset);
    free(core->buffer);
}

static int jmp_next_syscall(strace_t *strace)
{
    long opcode = 0;

    if (ptrace(PTRACE_GETREGS, strace->pid, NULL, &strace->core.regs) == -1)
        return -1;
    opcode = ptrace(PTRACE_PEEKTEXT, strace->pid, strace->core.regs.rip, 0);
    if (opcode == -1)
        return -1;
    ptrace(PTRACE_SINGLESTEP, strace->pid, NULL, NULL);
    waitpid(strace->pid, &strace->core.status, 0);
    return ((unsigned long)opcode & 0xffff) != 0x050f;
}

void core_strace(strace_t *strace, core_strace_t *core)
{
    int value = 0;

    waitpid(strace->pid, &core->status, 0);
    while (check_if_quit(strace, core)) {
        value = jmp_next_syscall(strace);
        if (value == -1)
            break;
        if (value == 1)
            continue;
        tracer(strace, core);
    }
}
