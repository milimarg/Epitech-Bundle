/*
** EPITECH PROJECT, 2022
** CPOOL_Day06
** File description:
** my_strstr.c
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

char *my_strstr(char *str, char const *to_find)
{
    int global_len;
    int needle_len;
    int i;
    int j;
    int z;

    global_len = 0;
    needle_len = 0;
    i = 0;
    j = 0;
    z = 0;
    while (str[global_len] != '\0')
        global_len++;
    while (to_find[needle_len] != '\0')
        needle_len++;
    while (str[i] != '\0') {
        if (str[i] == to_find[j])
            z++;
        if (str[i + 1] == '\0' && z != needle_len) {
            j++;
            i = 0;
        }
        //if (str[z] == to_find[needle_len])
        //    break;
        i++;
    }
    printf("%d", z - 1);
    //for (int y = global_len - z; y < global_len; y++)
        //my_putchar(str[y]);
    return "";
}

int main(void)
{
    char *test = my_strstr("titi est assis en face de toto ahahah", "titi est");
    printf("%s", test);
    return 0;
}
