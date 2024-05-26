/*
** EPITECH PROJECT, 2022
** CPOOL_Day07_task06
** File description:
** main.c
*/

void my_putchar(char c);

void my_putstr(char const *str);

void arg_letter_checker(int i, int j, char **argv)
{
    if (argv[j][0] == i) {
        my_putstr(argv[j]);
        my_putchar('\n');
    }
}

void arg_checker(int i, int argc, char **argv)
{
    for (int j = 0; j < argc; j++)
        arg_letter_checker(i, j, argv);
}

int main(int argc, char **argv)
{
    for (int i = 0; i <= 127; i++)
        arg_checker(i, argc, argv);
    return 0;
}
