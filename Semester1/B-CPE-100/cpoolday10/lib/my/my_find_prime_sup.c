/*
** EPITECH PROJECT, 2022
** CPOOL_Day05
** File description:
** my_find_prime_sup.c
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int a;
    int i;

    i = nb;
    a = my_is_prime(i);
    while (!a) {
        i++;
        a = my_is_prime(i);
    }
    return i;
}
