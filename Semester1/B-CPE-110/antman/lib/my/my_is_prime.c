/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** Gentil Mouli !
*/

int my_is_prime(int nb)
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
