/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGRUSH2-florent.guittre
** File description:
** tests_new.c
*/

#include "../new.h"
#include "../player.h"
#include <criterion/criterion.h>

Test(new, create_player)
{
    Object *player = new(Player);

    cr_assert_not_null(player);
    delete(player);
}
