/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

int print_game(sfRenderWindow *window, global_t *global, game_object_t **map)
{
    for (int i = 0; i < (global->len * global->col - global->air); i++)
        sfRenderWindow_drawSprite(window, map[i]->sprite, NULL);
    sfRenderWindow_drawText(window, global->score.text, NULL);
    sfRenderWindow_drawSprite(window, global->player->sprite, NULL);
    return (0);
}
