/*
** EPITECH PROJECT, 2022
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

int check_air(char c)
{
    if (c == ' ')
        return (1);
    return (0);
}

void get_nb_air(global_t *global, char **map)
{
    int i;
    int j;

    global->air = 0;
    for (i = 0; i < global->len; i++) {
        for (j = 0; j < global->col; j++)
            global->air += check_air(map[i][j]);
    }
}
