/*
** EPITECH PROJECT, 2022
** All_prototypes
** File description:
** vous etes dans l'abus
*/

#ifndef ZOZO
    #define ZOZO

    typedef struct stlemin_a {
        char *input;
        int nb_of_start;
        int nb_of_end;
        int start_room;
        int end_room;
        int ant_nbr;
        char ***rooms;
        int room_nbr;
        int link_nbr;
        int nb;
        int nbr_way;
        int distance;
        int stop_recursive;
        int **matrix;
        int **array_way;
        int i;
        int j;
        char **rooms_names;
    } stlemin_t;

    typedef struct slot {
        int ant_nb;
        int ant_index;
    } slot;

#endif
