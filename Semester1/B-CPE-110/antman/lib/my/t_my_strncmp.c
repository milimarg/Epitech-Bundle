/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-antman-florent.guittre
** File description:
** test
*/

int t_my_strncmp(const char *s1, const char *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (*s1 != *s2)
            return (1);
        s1++;
        s2++;
    }
    return (0);
}
