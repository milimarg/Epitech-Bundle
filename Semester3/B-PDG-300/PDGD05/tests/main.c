/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** main.c
*/

#include <stdio.h>
#include "../string.h"

int main ( void )
{
    string_t s ;
    string_init (& s , " " ) ;
    s.assign_c (& s , " Hello World " ) ;
    printf ( " %s \n " , s.str ) ;
    string_destroy (& s ) ;
    return (0) ;
}
