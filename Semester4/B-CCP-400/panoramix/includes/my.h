/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-panoramix-florent.guittre
** File description:
** my.h
*/

#ifndef B_CCP_400_STG_4_1_PANORAMIX_FLORENT_GUITTRE_MY_H
    #define B_CCP_400_STG_4_1_PANORAMIX_FLORENT_GUITTRE_MY_H
    #include <stdlib.h>
    #include <pthread.h>
    #include <semaphore.h>
    #include <stdio.h>
    #include <unistd.h>

typedef struct {
    pthread_t thread;
    int *nb_refills;
    int *pot_size_max;
    int *current_pot_size;
} druid_t;

typedef struct {
    int id;
    int remaining_fights;
    int fights;
    int *current_pot_size;
    pthread_t thread;
} villager_t;

typedef struct {
    int nb_villagers;
    int *pot_size_max;
    int *current_pot_size;
    int *remaining_fights;
    int *nb_refills;
    villager_t *villagers;
    druid_t druid;
    int nb_awake_villagers;
} panoramix_t;

typedef struct {
    panoramix_t *panoramix;
    pthread_mutex_t *pot_mutex;
    sem_t *pot_semaphore;
    sem_t *pot_semaphore2;
    size_t index;
} universe_t;

#endif
