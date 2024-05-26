/*
** EPITECH PROJECT, 2022
** B-MUL-100-STG-1-1-myradar-florent.guittre
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
int run_game(my_window *window, game_t *game, char *timer);
int my_strlen(char const *str);
int get_infos(game_t *game, char *filename);
int init_entities(game_t *game);
void display_elements(my_window *window, game_t *game);
void move_entity_manager(game_t *game);
int get_coeff_move_airplane(airplane_t *airplane);
void timer_update(char timer[]);
int set_timer_object(game_t *game, char *timer_str, my_window *window);
void time_manager(int *seconds_temp, char *timer, game_t *game);
double get_direction_angle(airplane_t *airplane);
void display_help(void);
int argv_parsing(int argc, char **argv);
int check_airplane_collision(airplane_t *current_airplane, airplane_t *head,
game_t *game);
int remove_node(airplane_t **head, airplane_t *node_to_remove);
int free_airplane(airplane_t *airplane);
int frees(char *timer, game_t *game, my_window *window);
void update_color(airplane_t *airplane);
#endif /* !MY_H_ */
