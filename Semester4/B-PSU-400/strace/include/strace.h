/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-strace-florent.guittre
** File description:
** strace
*/

#ifndef STRACE_H_
    #define STRACE_H_
    #include <stdbool.h>
    #include <sys/ptrace.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/user.h>
    #include <string.h>
    #include <errno.h>
    #include <sys/stat.h>
    #include <signal.h>

    #include "syscall.h"

    #define UNUSED __attribute__((unused))
    #define TO_STR(x) #x

typedef struct {
    int non;
    int s;
    int p;
} flags_t;

typedef struct {
    struct user_regs_struct regs;
    long long int registers[6];
    int args[6];
    int status;
    char *buffer;
} core_strace_t;


// for the stat syscall -s option
typedef struct {
    int first;
    const char *second;
} pair;

static const pair arg_stat[] = {
    {0, "S_IFSOCK|"},
    {1, "S_IFLNK|"},
    {2, "S_IFREG|"},
    {3, "S_IFBLK|"},
    {4, "S_IFDIR|"},
    {5, "S_IFCHR|"},
    {6, "S_IFIFO|"},
};

typedef struct {
    bool flag_p;
    bool flag_s;
    pid_t pid;
    char **binary;
    flags_t flags;
    char *abspath;
    char **envp;
    core_strace_t core;
    unsigned int rdx;
} strace_t;

int strace(strace_t *strace);
int get_flags(int argc, char **argv, strace_t *strace);
char *get_env_path(char *binary_name, char **envp);

// Strace init functions
bool handle_attach(strace_t *strace);
bool handle_fork(strace_t *strace);

// Strace core function
void core_strace(strace_t *strace, core_strace_t *core);

// Strace utils functions
void store_args(int *args, syscall_t syscall);
void store_registers(long long int *registers,
    struct user_regs_struct *regs);
void strace_print(char *str, unsigned long long int value);
void store_display(strace_t *strace, int *offset, long long addr, int argnb);
char *handle_struct_stat_p(strace_t *strace, long long addr,
    long long *value);
#endif /* !STRACE_H_ */
