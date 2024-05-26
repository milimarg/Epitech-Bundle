/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-lemin-florent.guittre
** File description:
** sec_part_eh
*/

#include "../includes/lmin.h"

int is_alph(stlemin_t *s, int i, int mod)
{
    if (mod == 0) {
        if (s->input[i] < '0' || s->input[i] > '9')
            return 84;
    } if (mod == 1) {
        if ((s->input[i] < '0' || s->input[i] > '9') && (s->input[i] < 'a' ||
            s->input[i] > 'z') && (s->input[i] < 'A' || s->input[i] > 'Z'))
            return 84;
    }
    return 0;
}

int c_start(stlemin_t *s, int *i)
{
    if (s->input[*i + 1] == 's' && s->input[*i + 2] == 't' && s->input[*i + 3]
== 'a' && s->input[*i + 4] == 'r' && s->input[*i + 5] == 't' && (s->input[*i
        + 6] == '\n' || s->input[*i + 6] == ' ')) {
            if ((*(i) = skip_space_and_comment(s, *(i) + 6)) == -1) {
                *(i) = -700;
                return 0;
            }
        s->start_room = s->nb;
        *(i) = get_room_n(s, *(i));
        s->nb_of_start++;
        s->room_nbr++;
        return 0;
    }
    return 1;
}

int second_part(stlemin_t *s)
{
    int m;
    for (int i = s->room_nbr + 2; i < s->room_nbr + s->link_nbr + 1; i++) {
        m = 0;
        for (int j = 1; j < s->room_nbr + 1; j++)
            m = my_str_compare(s->rooms[i][0], s->rooms[j][0]) == 1 ? 1 : m;
        if (m == 0) {
            s->nb = i;
            return 84;
        }
        m = 0;
        for (int j = 1; j < s->room_nbr + 1; j++)
            m = my_str_compare(s->rooms[i][1], s->rooms[j][0]) == 1 ? 1 : m;
        if (m == 0) {
            s->nb = i;
            return 84;
        }
    }
    return 0;
}

int malloc_array(stlemin_t *s, int lines)
{
    s->room_nbr = 0;
    s->link_nbr = 0;
    s->nb = 0;
    s->nb_of_start = 0;
    s->nb_of_end = 0;
    s->ant_nbr = 0;
    if (lines == -700)
        return 84;
    s->rooms = malloc(sizeof(char **) * lines);
    for (int i = 0; i < lines - 1; i++) {
        s->rooms[i] = malloc(sizeof(char *) * 4);
        for (int j = 0; j < 4; j++)
            s->rooms[i][j] = malloc(sizeof(char) * 10);
    }
    return 0;
}

int get_input_file(stlemin_t *stlemin)
{
    char *buf = NULL;
    int total_bytes = 0;
    int line = 0;
    char *tmp = malloc(sizeof(char) * 1000000);
    size_t n = 0;
    for (; n != -1; total_bytes++ & line++) {
        n = getline(&buf, &n, stdin);
        if (n == -1)
            break;
        my_strcat(tmp, buf);
        for (int i = 0; buf[i] != '\n' && buf[i] != '\0'; i++ & total_bytes++);
    } tmp = n_at_end(tmp);
    total_bytes--;
    stlemin->input = malloc(sizeof(char) * total_bytes);
    if (line < 5 || hashtag(tmp) == 1) {
        free(tmp);
        return -700;
    } my_strcat(stlemin->input, tmp);
    free(tmp);
    return line;
}
