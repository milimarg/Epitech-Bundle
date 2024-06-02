/*
** EPITECH PROJECT, 2024
** Bootstrap_ftrace
** File description:
** toto.c
*/

#include <unistd.h>

void toto()
{
    write(1, "i am in toto()\n", 15);
}

void tutu()
{
    write(1, "i am in tutu()\n", 15);
}

int main(void)
{
    toto();
    tutu();
    return 0;
}
