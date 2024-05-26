/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-lemin-florent.guittre
** File description:
** main
*/

#include "includes/lmin.h"

int find_distance(stlemin_t *stlemin)
{
    for (int i = 0; i < stlemin->room_nbr; i++) {
        if (stlemin->matrix[stlemin->start_room][i] != -1)
            return (stlemin->matrix[stlemin->start_room][i]);
    }
    return (0);
}

int display(stlemin_t *stlemin)
{
    int o = 0;
    int ok = 0;
    int op = 0;
    int plus = 0;
    if (stlemin->ant_nbr < 1)
        return 84;
    write(1, "#number_of_ants\n", 16);
    if (stlemin->nb > 1)
        plus = 2;
    for (int i = 0; o < stlemin->nb + plus; i++) {
        if (o == 1 && ok == 0) {
            write(1, "#rooms\n", 7);
            ok = 1;
        } if (o == stlemin->room_nbr + 3 && op == 0 && stlemin->nb_of_start !=
            1 && stlemin->nb_of_end != 1) {
            write(1, "#tunnels\n", 9);
            op = 1;
        } o = stlemin->input[i] == '\n' ? o + 1 : o;
        my_printf("%c", stlemin->input[i]);
    }
}

int main(void)
{
    stlemin_t stlemin = {0};

    if (malloc_array(&stlemin, get_input_file(&stlemin)) == 84)
        return 84;
    if (main_path_handling(&stlemin, 0) == 84 || second_part(&stlemin) == 84) {
        display(&stlemin);
        free_all(stlemin);
        return (84);
    }
    display(&stlemin);
    if (lem_in(&stlemin) == 84)
        return (84);
    free_all(stlemin);
    return (0);
}
