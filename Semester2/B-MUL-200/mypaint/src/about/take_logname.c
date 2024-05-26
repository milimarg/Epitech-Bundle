/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** take_logname
*/

#include <stdlib.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/my.h"
#include "../../include/about.h"
#include "../../my_csfml/lib/lib.h"

static int my_strncmp(char *s1, char *s2, int n)
{
    int s1_len = my_strlen(s1);
    int s2_len = my_strlen(s2);

    for (int i = 0; i < s1_len && i < n || i < s2_len && i < n; i++)
        if (s1[i] != s2[i])
            return ((s1_len < s2_len) ? -1 : 1);
    return (0);
}

static void take_log(char *log, my_paint *p)
{
    int i = 0;
    int len = my_strlen(log);
    p->about->log_name = malloc(sizeof(char) * (len + 9));
    int k = 8;

    for (int i = 0; i < (len + 9); i++)
        p->about->log_name[i] = '\0';
    for (; log[i] != '='; i++);
    i++;
    p->about->log_name = my_strcat(p->about->log_name, "LOGIN : ");
    for (; log[i]; i++) {
        p->about->log_name[k] = log[i];
        k++;
    }
    p->about->log_name[k] = '\0';
}

void take_logname(my_paint *p)
{
    for (int i = 0; p->env[i]; i++) {
        if (my_strncmp("LOGNAME=", p->env[i], 8) == 0)
            take_log(p->env[i], p);
    }
}
