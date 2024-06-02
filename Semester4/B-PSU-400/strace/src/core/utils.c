/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-strace-florent.guittre
** File description:
** utils
*/

#include "../../include/strace.h"

void store_args(int *args, syscall_t syscall)
{
    args[0] = syscall.arg1;
    args[1] = syscall.arg2;
    args[2] = syscall.arg3;
    args[3] = syscall.arg4;
    args[4] = syscall.arg5;
    args[5] = syscall.arg6;
}

void store_registers(long long int *registers,
    struct user_regs_struct *regs)
{
    registers[0] = regs->rdi;
    registers[1] = regs->rsi;
    registers[2] = regs->rdx;
    registers[3] = regs->r10;
    registers[4] = regs->r8;
    registers[5] = regs->r9;
}

void strace_print(char *str, unsigned long long int value)
{
    write(2, str, value);
}
