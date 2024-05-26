/*
** EPITECH PROJECT, 2022
** CPOOL_Day08
** File description:
** my_show_word_array.c
*/

void my_putstr(char const *str);

void my_putchar(char c);

int my_show_word_array(char * const *tab)
{
    int i;

    i = 0;
    while (tab[i] != 0) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}
