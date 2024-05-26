/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** Magnifique Mouli !
*/

static int next(int nb, int m)
{
    while (m * m != nb) {
        if (m > (nb / 2) ) {
            nb = 0;
            return (nb);
        } if ( m <= (nb / 2))  {
            m = m +1;
        }
    }
    nb = nb / m;
    return (nb);
}

int my_compute_square_root(int nb)
{
    int m = 0;
    if (nb > 0) {
        next(nb, m);
    } else {
        nb = 0;
        return (nb);
            }
}
