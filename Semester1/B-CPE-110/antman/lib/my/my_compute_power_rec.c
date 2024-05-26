/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** La Mouli est vraiment drôle
*/

long long  my_compute_power_rec(int nb, int p)
{
    int result;
    result = nb;
    if (p == 0){
        result = 1;
    } if (p < 0){
        result = 0;
    } if (p > 0){
        result = my_compute_power_rec(nb, p - 1) * nb;
    }
    return (result);
}
