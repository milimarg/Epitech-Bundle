/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-lemin-florent.guittre
** File description:
** error_handling
*/

#include "../includes/lmin.h"

static int get_link(stlemin_t *s, int i, int k)
{
    for (; s->input[i] != '-'; i++ & k++) {
        if (is_alph(s, i, 1) == 84)
            return -700;
        s->rooms[s->nb][0][k] = s->input[i];
    } s->rooms[s->nb][0][k] = '\0';
    k = 0;
    for (i = i + 1; s->input[i] != ' ' && s->input[i] != '\n' && s->input[i]
        != '\0'; i++ & k++) {
        if (is_alph(s, i, 1) == 84 && s->input[i] != '\n' && s->input[i]
            != '\0')
            return -700;
        s->rooms[s->nb][1][k] = s->input[i];
    } s->rooms[s->nb][1][k] = '\0';
    if (s->input[i] == ' ') {
        if (skip_space_and_comment(s, i) == -1)
            return -700;
        s->nb++;
        return i;
    } s->nb++;
    return i + 1;
}

static int check_comment(stlemin_t *s, int j)
{
    int n_s = 0;
    int i = j;
    for (; s->input[i] != '\n' && n_s < 3 && s->input[i] != '\0'; i++) {
        if (n_s == 0 && is_alph(s, i, 1) == 84 && s->input[i] != ' ')
            return 1;
        if (n_s > 0 && is_alph(s, i, 0) == 84 && s->input[i] != ' ')
            return 1;
        n_s = s->input[i] == ' ' ? n_s + 1 : n_s;
        if (n_s > 2)
            i = skip_space_and_comment(s, i);
        if (i == -1)
            return 1;
    }
    return 0;
}

static int check_numbers(stlemin_t *s, int i)
{
    int save = i;
    for (; is_alph(s, i, 1) != 84; i++);
    if (s->input[i] == '-') {
        i = get_link(s, save, 0);
        s->link_nbr++;
        return i;
    } if (s->input[i] == ' ') {
        int error = check_comment(s, save);
        if (error == 1)
            return -700;
        i = get_room_n(s, save);
        s->room_nbr++;
        return i;
    }
    return -700;
}

static int check_command(stlemin_t *s, int i)
{
    if (s->input[i] != '#') {
        for (; s->input[i] != '\n'; i++);
        return i + 1;
    } else {
        if (c_start(s, &i) == 0)
            return i;
        if ((i = check_command_sec(s, i)) != -700)
            return i;
        return -700;
    }
}

int main_path_handling(stlemin_t *s, int i)
{
    if (get_ant_nb(s, &i) == 84 || s->ant_nbr < 1)
        return 84;
    while (s->input[i] != '\0' && i != -700) {
        if (s->input[i] == ' ')
            i = skip_l_space(s, i);
        if (is_alph(s, i, 1) == 84 && s->input[i] != '#')
            return 84;
        if (is_alph(s, i, 1) == 0)
            i = check_numbers(s, i);
        if (i == -700)
            return 84;
        if (s->input[i] == '#')
            i = check_command(s, (i + 1));
        if (is_alph(s, i, 1) == 84 && s->input[i] != '#' && s->input[i] != ' ')
            s->rooms[s->nb] = NULL;
    } if (i == -700 || s->nb_of_start != 1 || s->nb_of_end != 1 || s->link_nbr >
        (s->room_nbr * s->room_nbr)) {
            no_cmd(s);
            return 84;
        } return 0;
}
