/*
** EPITECH PROJECT, 2022
** CPOOL_CWorkshopLib
** File description:
** my_find_prime_sup.c
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int i = nb;
    int a = my_is_prime(i);

    while (!a) {
        i++;
        a = my_is_prime(i);
    }
    return i;
}
