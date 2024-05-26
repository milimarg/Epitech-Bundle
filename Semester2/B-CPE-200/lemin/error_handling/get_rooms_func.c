/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-lemin-florent.guittre
** File description:
** get_rooms_func
*/

#include "../includes/lmin.h"

int skip_space_and_comment(stlemin_t *s, int i)
{
    int h = 0;
    for (; s->input[i] != '\n' && s->input[i] != '\0'; i++) {
        if (s->input[i] == '#' && s->input[i + 1] != '#') {
            i += 2;
            h = 1;
        }
        if (s->input[i] != ' ' && h == 0)
            return -1;
    }
    return i + 1;
}

int get_room_n(stlemin_t *s, int i)
{
    int k = 0;
    int j = 0;
    int n_s = 0;
    for (; s->input[i] != '\n' && n_s < 3; i++) {
        for (j = 0; s->input[i] != ' ' && s->input[i] != '\n'; i++ & j++)
            s->rooms[s->nb][k][j] = s->input[i];
        s->rooms[s->nb][k][j] = '\0';
        k++;
        if (s->input[i] == ' ')
            n_s++;
        if (s->input[i] == '\n')
            break;
    } s->rooms[s->nb][k] = NULL;
    if (n_s > 2) {
        if ((i = skip_space_and_comment(s, i)) == -1)
            return -700;
        s->nb++;
        return i;
    } s->nb++;
    return i + 1;
}

void end_ant(stlemin_t *stlemin, int *i, int save)
{
    if (save != 0) {
        stlemin->rooms[stlemin->nb][0][save] = '\0';
        stlemin->rooms[stlemin->nb][1] = NULL;
        stlemin->nb++;
    } else {
        stlemin->rooms[stlemin->nb][0][*i] = '\0';
        stlemin->rooms[stlemin->nb][1] = NULL;
        stlemin->nb++;
        (*i)++;
    }
    stlemin->ant_nbr = my_getnbr(stlemin->rooms[0][0]);
}

int get_ant_nb(stlemin_t *stlemin, int *i)
{
    int save = 0;
    for (;stlemin->input[*i] != '\n' && stlemin->input[*i] != '\0'; (*i)++) {
        if (stlemin->input[*i] == ' ') {
            save = *i;
            *i = skip_space_and_comment(stlemin, *i);
            break;
        }
        if (stlemin->input[*i] < '0' || stlemin->input[*i] > '9')
            return 84;
        stlemin->rooms[0][0][*i] = stlemin->input[*i];
    }
    if (*i == -1)
        return 84;
    end_ant(stlemin, i, save);
    return 0;
}
