/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-florent.guittre
** File description:
** parsing_help
*/

#include <unistd.h>

int my_strcmp(const char *s1, const char *s2);

void display_help(void)
{
    char *str = "Air traffic simulation panel\n\n"
                "USAGE\n"
                "./my_radar [path_to_script|OPTIONS]\n"
                "path_to_script    The path to the script without comments.\n\n"
                "OPTIONS\n"
                "-h    print the usage and quit.\n\n"
                "USER INTERACTION\n"
                "'L' key    display/hide hitboxes and areas.\n"
                "'S' key    display/hide sprites.\n"
                "'R' key    display/hide rainbow on airplanes's hitboxes.\n"
                "ESC key    quit.\n";
    write(1, str, 342);
}

int argv_parsing(int argc, char **argv)
{
    if (argc != 2)
        return (84);
    if (!my_strcmp(argv[1], "-h")) {
        display_help();
        return (0);
    }
    return (1);
}
