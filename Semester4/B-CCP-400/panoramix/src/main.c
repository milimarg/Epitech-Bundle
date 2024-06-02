/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-panoramix-florent.guittre
** File description:
** main.c
*/

#include "../includes/my.h"

static void refill_druid(druid_t *druid)
{
    *druid->current_pot_size = *druid->pot_size_max - 1;
    (*(druid->nb_refills))--;
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! "
    "Beware I can only make %d more refills after this one.\n",
    *druid->nb_refills);
}

static void *spawn_druid(void *data)
{
    universe_t *universe = (universe_t *)data;
    druid_t *druid = &universe->panoramix->druid;

    printf("Druid: I'm ready... but sleepy...\n");
    while (*druid->nb_refills > 0) {
        sem_wait(universe->pot_semaphore2);
        if (universe->panoramix->nb_awake_villagers == 0)
            break;
        refill_druid(druid);
        sem_post(universe->pot_semaphore);
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return NULL;
}

void fight_villager(universe_t *universe, villager_t *villager)
{
    villager->fights++;
    villager->remaining_fights--;
    printf("Villager %d: Take that roman scum! Only %d left.\n", villager->id,
    villager->remaining_fights);
    pthread_mutex_unlock(universe->pot_mutex);
}

int drink_villager(villager_t *villager)
{
    printf("Villager %d: I need a drink... I see %d servings left.\n",
    villager->id, *villager->current_pot_size);
    if (*villager->current_pot_size == 0)
        return 0;
    (*(villager->current_pot_size))--;
    return 1;
}

void *spawn_villager(void *data)
{
    universe_t *universe = (universe_t *)data;
    villager_t *villager = &universe->panoramix->villagers[universe->index];

    printf("Villager %d: Going into battle!\n", villager->id);
    while (villager->remaining_fights > 0) {
        pthread_mutex_lock(universe->pot_mutex);
        if (!drink_villager(villager)) {
            printf("Villager %d: Hey Pano wake up! We need more potion.\n",
            villager->id);
            sem_post(universe->pot_semaphore2);
            sem_wait(universe->pot_semaphore);
        }
        fight_villager(universe, villager);
        usleep(1000000);
    }
    printf("Villager %d: I'm going to sleep now.\n", villager->id);
    universe->panoramix->nb_awake_villagers--;
    if (universe->panoramix->nb_awake_villagers == 0)
        sem_post(universe->pot_semaphore2);
    return NULL;
}

static void add_and_free_elements(universe_t *univs, panoramix_t *panoramix)
{
    universe_t *universe = &univs[0];

    pthread_create(&univs[0].panoramix->druid.thread, NULL, &spawn_druid,
    &univs[0]);
    for (int i = 0; i < panoramix->nb_villagers; i++)
        pthread_create(&univs[i].panoramix->villagers[i].thread, NULL,
        &spawn_villager, &univs[i]);
    pthread_join(panoramix->druid.thread, NULL);
    for (int i = 0; i < panoramix->nb_villagers; i++)
        pthread_join(panoramix->villagers[i].thread, NULL);
    free(panoramix->villagers);
    free(panoramix->pot_size_max);
    free(panoramix->current_pot_size);
    free(panoramix->remaining_fights);
    free(panoramix->nb_refills);
    pthread_mutex_destroy(universe->pot_mutex);
    sem_destroy(universe->pot_semaphore);
    sem_destroy(universe->pot_semaphore2);
    free(universe->pot_mutex);
}

void thread_creator(panoramix_t *panoramix)
{
    universe_t *univs = malloc(sizeof(universe_t) * panoramix->nb_villagers);
    pthread_mutex_t *pot_mutex = malloc(sizeof(pthread_mutex_t));
    sem_t *pot_semaphore = malloc(sizeof(sem_t));
    sem_t *pot_semaphore2 = malloc(sizeof(sem_t));

    pthread_mutex_init(pot_mutex, NULL);
    sem_init(pot_semaphore, 0, 0);
    sem_init(pot_semaphore2, 0, 0);
    for (int i = 0; i < panoramix->nb_villagers; i++) {
        univs[i].panoramix = panoramix;
        univs[i].pot_semaphore = pot_semaphore;
        univs[i].pot_semaphore2 = pot_semaphore2;
        univs[i].pot_mutex = pot_mutex;
        univs[i].index = i;
    }
    add_and_free_elements(univs, panoramix);
    free(univs[0].pot_semaphore);
    free(univs[0].pot_semaphore2);
    free(univs[0].panoramix);
    free(univs);
}

static int fill_struct2(char **argv, panoramix_t *panoramix)
{
    int nb_refills = atoi(argv[4]);

    if (nb_refills <= 0)
        return 84;
    panoramix->nb_refills = malloc(sizeof(int));
    *panoramix->nb_refills = nb_refills;
    panoramix->villagers = malloc(sizeof(villager_t) *
    panoramix->nb_villagers);
    return 0;
}

static int fill_struct(char **argv, panoramix_t *panoramix)
{
    int pot_size = 0;
    int remaining_fights = 0;

    panoramix->nb_villagers = atoi(argv[1]);
    if (panoramix->nb_villagers <= 0)
        return 84;
    pot_size = atoi(argv[2]);
    if (pot_size <= 0)
        return 84;
    panoramix->pot_size_max = malloc(sizeof(int));
    *panoramix->pot_size_max = pot_size;
    panoramix->current_pot_size = malloc(sizeof(int));
    *panoramix->current_pot_size = pot_size;
    remaining_fights = atoi(argv[3]);
    if (remaining_fights <= 0)
        return 84;
    panoramix->remaining_fights = malloc(sizeof(int));
    *panoramix->remaining_fights = remaining_fights;
    return fill_struct2(argv, panoramix);
}

int main(int argc, char **argv)
{
    villager_t *villager = NULL;
    panoramix_t *panoramix = malloc(sizeof(panoramix_t));

    if (argc != 5 || fill_struct(argv, panoramix) == 84) {
        free(panoramix);
        return 84;
    }
    panoramix->druid.nb_refills = panoramix->nb_refills;
    panoramix->druid.pot_size_max = panoramix->pot_size_max;
    panoramix->druid.current_pot_size = panoramix->current_pot_size;
    panoramix->nb_awake_villagers = panoramix->nb_villagers;
    for (int i = 0; i < panoramix->nb_villagers; i++) {
        villager = &panoramix->villagers[i];
        villager->id = i;
        villager->remaining_fights = *panoramix->remaining_fights;
        villager->current_pot_size = panoramix->current_pot_size;
        villager->fights = 0;
    }
    thread_creator(panoramix);
    return 0;
}
