/*
** EPITECH PROJECT, 2022
** rush2
** File description:
** display utility for rush2.
*/

void my_putchar(char c);

void my_putstr(char const *str);

int my_put_nbr(int nb);

int check_char(char c);

void display_checker(int i, char *letters, int count[], float *freq)
{
    int decimal;

    if (check_char(letters[i])) {
        decimal = (freq[i] - (int)freq[i]) * 100;
        my_putchar(letters[i]);
        my_putchar(':');
        my_put_nbr(count[i]);
        my_putstr(" (");
        my_put_nbr((int)freq[i]);
        my_putchar('.');
        if (freq[i] == 0)
            my_putstr("00");
        else
            my_put_nbr(decimal);
        my_putstr("%)\n");
    }
}

void display_letters(char *letters, int count[], int len, float *freq)
{
    for (int i = 0; i < len; i++)
        display_checker(i, letters, count, freq);
}
