/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** good prog
*/

static int my_is_prime_next(int nb)
{
    int h = 1;
    int end;
    if (nb <= 1) {
        return (0);
    }
    if (nb == 2) {
        return (1);
            }
    while (h < nb - 1) {
        h++;
        if (nb % h != 0 || nb % h != nb){
            end = 1;
        } if (nb % h == 0 || nb % h == nb){
            end = 0;
            break;
        }
    }
    return (end);
}

int my_find_prime_sup(int nb)
{
    int h = nb;
    int end;
    while (h >= nb) {
        if (my_is_prime_next(h)) {
            return (h);
        }
    h++;
    }
}
