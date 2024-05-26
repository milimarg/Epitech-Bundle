/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-lemin-florent.guittre
** File description:
** pars_func
*/

#include "../includes/lmin.h"

char *n_at_end(char *tmp)
{
    for (int i = 0; tmp[i] != '\0'; i++) {
        if (tmp[i + 1] == '\0' && tmp[i] != '\n') {
            tmp[i + 1] = '\n';
            tmp[i + 2] = '\0';
            break;
        }
    }
    return tmp;
}

int skip_l_space(stlemin_t *stlemin, int i)
{
    for (; stlemin->input[i] == ' '; i++);
    return i;
}

int check_command_sec(stlemin_t *s, int i)
{
    if (s->input[i + 1] == 'e' && s->input[i + 2] == 'n' &&
        s->input[i + 3] == 'd' && (s->input[i + 4] == ' ' || s->input[i +
        4] == '\n')) {
            if ((i = skip_space_and_comment(s, i + 4)) == -1)
                return -700;
            s->end_room = s->nb;
            i = get_room_n(s, i);
            s->nb_of_end++;
            s->room_nbr++;
        return i;
    }

}

void no_cmd(stlemin_t *s)
{
    int o = 0;
    if ((s->nb_of_start < 1 || s->nb_of_end < 1) && s->room_nbr > 0) {
        for (int i = 0; s->input[i] != '-' && s->input[i] != '\0'; i++)
            o = s->input[i] == '\n' ? o + 1 : o;
    }
    s->nb = o - 2;
}

int hashtag(char *tmp)
{
    int hashtag = 0;
    for (int i = 0; tmp[i] != '\0'; i++)
        hashtag = tmp[i] == '#' ? hashtag + 1 : hashtag;
    if (hashtag >= 4)
        return 0;
    else
        return 1;
}
