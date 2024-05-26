/*
** EPITECH PROJECT, 2023
** AIA
** File description:
** main
*/

#include "../include/my.h"

int check_my_buffer(char *buffer)
{
    static int end = 0;
    if (end)
        return (0);
    if (strstr(buffer, "First CP Cleared") != NULL)
        dprintf(2, "Cleared first CP\n");
    if (strstr(buffer, "CP Cleared") != NULL)
        dprintf(2, "Cleared CP\n");
    if (strstr(buffer, "Track Cleared") != NULL) {
        dprintf(2, "Track Cleared\n");
        end = 1;
        buffer = FWD(0);
        buffer = STOP;
        exit(0);
    }
    if (strstr(buffer, "WRONG WAY"))
        dprintf(2, "WRONG WAY\n");
    return (1);
}

void turn_to_angle_with_speed(char *buffer, float angle, float speed)
{
    buffer = TUR(angle);
    buffer = FWD(speed);
}

// CONFIG NOÉ
// float tab_ratio[] = {0.18, 0.3, 0.45, 0.70};
// float tab_speed[] = {0.15, 0.1, 0.05, 0.025};
// float tab_front[] = {750, 550, 450, 0};
// ratio à partir de 4 valeurs
// virage si devant > 400 et coté > 400;
// vitesse / 2;
//
// TIMER TRACK :
// 1 - 4:34:03
// 2 - 5:44:13
// 3 - 2:43:04
// 4 - 2:50:12
//
// CONFIG LANGOUSTINE
//1
// float tab_ratio[] = {0.0, 0.03, 0.05, 0.1, 0.2, 0.35, 0.5};
// float tab_speed[] = {1.0, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3};
// float tab_front[] = {1300, 1200, 1000, 800, 600, 500, 0};
//2
// float tab_ratio[] = {0.03, 0.05, 0.1, 0.2, 0.4, 0.65};
// float tab_speed[] = {0.8, 0.7, 0.6, 0.4, 0.3, 0.2};
// float tab_front[] = {1200, 1000, 800, 600, 500, 0};
//3
// float tab_ratio[] = {0.0, 0.03, 0.04, 0.06, 0.1, 0.2, 0.3, 0.35, 0.4, 0.5};
// float tab_speed[] = {1.0, 0.95, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2};
// float tab_front[] = {1300, 1200, 1100, 1000, 900, 800, 700, 600, 500, 0};
int compare_side_rays(char *buffer, float sign, float average_front)
{
    float tab_ratio[] = {0.18, 0.3, 0.45, 0.70};
    float tab_speed[] = {0.15, 0.1, 0.05, 0.025};
    float tab_front[] = {750, 550, 450, 0};
    for (int index = 0; index < 4; index++) {
        if (average_front >= tab_front[index]) {
            turn_to_angle_with_speed(buffer, tab_ratio[index] * sign,
            tab_speed[index]);
            break;
        }
    }
}

void loop(char *buffer, int end)
{
    char **lidar_info = NULL;
    float *front_rays = NULL;
    float average_front = 0.0;
    float average_left = 0.0;
    float average_right = 0.0;
    float sign = 0.0;
    while (end) {
        buffer = G_INF;
        lidar_info = my_str_to_word_array_specified(buffer, ':') + 3;
        front_rays = get_between_idx(lidar_info, 10, 22);
        average_left = get_between_idx(lidar_info, 0, 1)[0];
        average_right = get_between_idx(lidar_info, 31, 32)[0];
        average_front = compute_average_float(front_rays, 12);
        sign = (average_left - average_right < 0) ? -1.0 : 1.0;
        if (average_front > 400 && average_right > 400 && average_left > 400)
            turn_to_angle_with_speed(buffer, 0.0, 0.2);
        else
            compare_side_rays(buffer, sign, average_front);
        free_word_array(lidar_info - 3);
    }
}

int main(int ac, char **av)
{
    int end = 1;
    char *buffer = NULL;

    buffer = START;
    buffer = FWD(0.6);
    loop(buffer, end);
    return (0);
}
