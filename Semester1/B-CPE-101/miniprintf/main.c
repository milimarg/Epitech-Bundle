/*
** EPITECH PROJECT, 2022
** CPOOL_mini_printf
** File description:
** main.c
*/

int mini_printf(const char *format, ...);

int main(void)
{
    mini_printf("Hello I'm %s and I'm %d yo! I like the letters %c and %c... %%!", "Ganesh", 42, 'g', 'h');
    return (0);
}
