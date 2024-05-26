/*
** EPITECH PROJECT, 2022
** CPOOL_Day12_task01
** File description:
** main.c
*/

#include <errno.h>

int my_cat(char *file);

int my_cat_no_file(void);

int main(int argc, char **argv)
{
    int value = 0;

    if (argc == 1) {
        while (my_cat_no_file()) {
        }
        return (errno);
    }
    for (int i = 1; i < argc; i++) {
        my_cat(argv[i]);
    }
    return (0);
}
