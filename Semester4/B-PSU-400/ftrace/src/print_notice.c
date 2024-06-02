/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-ftrace-noe.tritsch
** File description:
** print_notice
*/

#include "syscall.h"

bool print_notice(int argc, char **argv)
{
    if (argc == 2) {
        if (strcmp(argv[1], "--help") == 0) {
            dprintf(2, "USAGE: ./ftrace <command>\n");
            return true;
        }
        if (strcmp(argv[1], "-h") == 0) {
            dprintf(2, "USAGE: ./ftrace <command>\n");
            return true;
        }
        return false;
    }
    return false;
}
