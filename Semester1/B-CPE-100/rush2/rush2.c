/*
** EPITECH PROJECT, 2022
** rush2
** File description:
** Counts occurences of a letter in a string.
*/

#include <stdio.h>

void my_putstr(const char*str);

int my_strlen(const char *str);

char *my_strlowcase(char *str);

char char_tolowcase(char letter);

char check_str(char *str);

int check_char(char c);

int strlen_alpha(char *str);

void display_letters(char *letters, int count[], int len, float *freq);

int check_lang(float frequency[], int letters_len, int letters_index[])
{
    const float LANGUAGES[4][26] = {
    {8.17, 1.50, 2.79, 4.25, 12.70, 2.23, 2.02, 6.09,
    6.97, 0.15, 0.77, 4.03, 2.41, 6.75, 7.51, 1.93, 0.01, 5.99, 6.33, 9.01,
    2.76, 0.98, 2.36, 0.15, 1.97, 0.07},
    {7.64, 0.90, 3.26, 3.67, 14.72, 1.07, 0.87, 0.74,
    7.53, 0.61, 0.07, 5.46, 2.97, 7.10, 5.80, 2.52, 1.36, 6.69, 7.95, 7.24,
    6.31, 1.84, 0.05, 0.43, 0.13, 0.33},
    {6.52, 1.89, 2.73, 5.08, 16.40, 1.60, 3.01, 4.58,
    6.55, 0.27, 1.42, 3.44, 2.53, 9.78, 2.59, 0.67, 0.02, 7.00, 7.27, 6.15,
    4.17, 0.85, 1.92, 0.03, 0.04, 1.13},
    {11.53, 2.22, 4.02, 5.01, 12.18, 0.69, 1.77, 0.70,
    6.25, 0.49, 0.01, 4.97, 3.16, 6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63,
    2.93, 1.14, 0.02, 0.22, 1.01, 0.47}
    };
    int letter_i;
    float temp[4];
    float add;

    my_putstr("----------\n");
    my_putstr("the lowest value is the predicted language for the sentence.\n");
    my_putstr("0 = English ; 1 = French ; 2 = German ; 3 = Spanish\n");
    for (int i = 0; i < 4; i++) {
        add = 0;
        for (int j = 0; j < letters_len; j++) {
            letter_i = letters_index[j];
            temp[i] = frequency[j] - (float)LANGUAGES[i][letter_i];
            add += temp[i];
        }
        printf("add of letters in language_index of %d = %.2f\n", i, add);
        my_putstr("-----\n");
    }
    return 0;
}

int check_index(float frequency[], int letters_len, char *letters)
{
    int a;
    int letters_index[letters_len];
    const char ALPHABET[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z'};

    a = 0;
    for (int i = 0; i < letters_len; i++) {
        for (int j = 0; j < 26; j++) {
            if (letters[i] == ALPHABET[j]) {
                letters_index[a] = j;
                a++;
            }
        }
    }
    check_lang(frequency, letters_len, letters_index);
    return 0;
}

int *check_occurences(char *str, char *letters, int letters_len)
{
    int count[letters_len];
    float frequency[letters_len];
    int global_len;

    global_len = strlen_alpha(str);
    for (int z = 0; z < letters_len; z++) {
        count[z] = 0;
        frequency[z] = 0.00;
    }
    str = my_strlowcase(str);
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; j < letters_len; j++) {
            count[j] = (str[i] == char_tolowcase(letters[j]))
            ? count[j] + 1 : count[j];
        }
    }
    for (int i = 0; i < letters_len; i++)
        frequency[i] = (((float)count[i]) * 100.00) / ((float)global_len);
    display_letters(letters, count, letters_len, frequency);
    check_index(frequency, letters_len, letters);
    return 0;
}

int main(int argc, char **argv)
{
    char letters[argc - 2];
    int letters_len = argc - 2;

    if (argc < 3)
        return 84;
    for (int i = 2; i < argc; i++) {
        letters[i - 2] = check_str(argv[i]);
    }
    check_occurences(argv[1], letters, letters_len);
    return 0;
}
