/*
** EPITECH PROJECT, 2022
** CPOOL_Day08
** File description:
** concat_params.c
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src);

char *concat_params(int argc, char **argv)
{
    int i;
    char *t;
    char *dest;
    int total_len;

    total_len = 0;
    for (i = 0; i < argc; i++)
        total_len += my_strlen(argv[i]);
    dest = malloc(sizeof(char) * (total_len + argc));
    for (i = 0; i < argc; i++) {
        t = (i < argc - 1) ? "\n" : "";
        my_strcat(dest, argv[i]);
        my_strcat(dest, t);
    }
    return dest;
}
