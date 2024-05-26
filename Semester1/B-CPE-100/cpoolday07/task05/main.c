/*
** EPITECH PROJECT, 2022
** CPOOL_Day07_task05
** File description:
** main.c
*/

void my_putchar(char c);

void my_putstr(char const *str);

int main(int argc, char **argv)
{
    for (int i = argc - 1; i >= 0; i--) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return 0;
}
