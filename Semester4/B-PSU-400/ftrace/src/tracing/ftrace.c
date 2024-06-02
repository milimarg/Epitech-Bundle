/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-ftrace-noe.tritsch
** File description:
** ftrace
*/

#include "syscall.h"

static void get_params(unsigned long long params[6], regs_t *params_regs)
{
    params[0] = params_regs->rdi;
    params[1] = params_regs->rsi;
    params[2] = params_regs->rdx;
    params[3] = params_regs->rcx;
    params[4] = params_regs->r8;
    params[5] = params_regs->r9;
}

static void display_syscall(ftrace_t *context, regs_t *params_regs,
    regs_t *ret_regs)
{
    syscall_t *current_sys = &table[params_regs->orig_rax];
    unsigned long long params[6] = {0};
    char *delim = "";

    if (!current_sys->mnemo)
        return;
    get_params(params, params_regs);
    dprintf(2, "Syscall %s(", current_sys->mnemo);
    for (int i = 0; i < current_sys->arg_count; ++i) {
        dprintf(2, "%s0x%llx", delim, params[i]);
        delim = ", ";
    }
    dprintf(2, ") = 0x%llx\n", ret_regs->rax);
}

static bool handle_functions(ftrace_t *context, long opcode, regs_t *regs,
    int *wstatus)
{
    pid_t pid = context->pid;
    char *fnc_name = NULL;

    if ((0xFF & opcode) == 0xE8) {
        fnc_name = get_function_name(context, regs->rip);
        if (fnc_name)
            dprintf(2, "Entering function %s at 0x%llx\n",
            fnc_name, regs->rip);
        return true;
    }
    if ((0xFF & opcode) == 0xC3) {
        opcode = ptrace(PTRACE_PEEKTEXT, pid, regs->rsp, 0);
        fnc_name = get_function_name(context, opcode - 5);
        if (fnc_name)
            dprintf(2, "Leaving function %s\n", fnc_name);
        return true;
    }
    return false;
}

static void handle_syscall(ftrace_t *context, long opcode, regs_t *regs,
    int *wstatus)
{
    regs_t regs_ret = {0};
    pid_t pid = context->pid;

    if (((unsigned long)opcode & 0xffff) == 0x050f) {
        ptrace(PTRACE_GETREGS, pid, NULL, regs);
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
        waitpid(pid, wstatus, 0);
        ptrace(PTRACE_GETREGS, pid, NULL, &regs_ret);
        display_syscall(context, regs, &regs_ret);
        return;
    }
}

static void start_loop(ftrace_t *context)
{
    int wstatus = 0;
    pid_t pid = context->pid;
    long opcode = 0;
    regs_t regs = {0};

    waitpid(pid, &wstatus, 0);
    while (WIFSTOPPED(wstatus)) {
        ptrace(PTRACE_GETREGS, pid, NULL, &regs);
        opcode = ptrace(PTRACE_PEEKTEXT, pid, regs.rip, NULL);
        if (opcode == -1)
            break;
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
        waitpid(pid, &wstatus, 0);
        if (!handle_functions(context, opcode, &regs, &wstatus))
            handle_syscall(context, opcode, &regs, &wstatus);
    }
    return;
}

void start_ftrace(ftrace_t *context)
{
    context->pid = fork();
    if (context->pid == 0) {
        ptrace(PT_TRACE_ME, 0, NULL, NULL);
        execvp(context->command[0], context->command);
        dprintf(2, "ftrace: Can't stat '%s': No such file or directory\n",
        context->command[0]);
        free(context);
        exit(84);
    } else {
        start_loop(context);
    }
}
