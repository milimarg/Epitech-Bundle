/*
** EPITECH PROJECT, 2022
** CPOOL_Day07_task04
** File description:
** main.c
*/

void my_putchar(char c);

void my_putstr(char const *str);

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return 0;
}
