/*
** EPITECH PROJECT, 2022
** CPOOL_Star
** File description:
** main.c
*/

int convert_string_to_int(char const *str);

void star(unsigned int size);

int main(int argc, char **argv)
{
    int size;

    if (argc == 2) {
        size = convert_string_to_int(argv[1]);
        star(size);
    }
    return 0;
}
