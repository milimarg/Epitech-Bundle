/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** signal_handler
*/

#include <signal.h>
#include "../include/my.h"

void sigtstp_handler(int signal)
{
    return;
}

void sigint_handler(int signal)
{
    return;
}

int signal_handler(void)
{
    signal(SIGTSTP, &sigtstp_handler);
    signal(SIGINT, &sigint_handler);
    return (0);
}
