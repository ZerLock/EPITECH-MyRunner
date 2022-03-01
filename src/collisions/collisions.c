/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

int is_pad(global_t *global, game_object_t **map, int i)
{
    if (global->player->pos.x < map[i]->pos.x + map[i]->rect.width - \
    map[i]->rect.width/2 && global->player->pos.x + \
    global->player->rect.width > map[i]->pos.x + map[i]->rect.width/2 &&
    global->player->pos.y < map[i]->pos.y + map[i]->rect.height &&
    global->player->pos.y + global->player->rect.height > map[i]->pos.y) {
        do_on_pad(global);
        return (0);
    }
    return (1);
}

int check_bloc_type(sfRenderWindow *window, global_t *global, \
game_object_t **map, int i)
{
    int return_val;

    if (map[i]->type == 1 || map[i]->type == 2 || map[i]->type == 3 ||
    map[i]->type == 5) {
        if (global->player->pos.x + \
        global->player->rect.width > map[i]->pos.x &&
        global->player->pos.x < map[i]->pos.x + map[i]->rect.width &&
        global->player->pos.y < map[i]->pos.y + map[i]->rect.height &&
        global->player->pos.y + global->player->rect.height > map[i]->pos.y)
            return (1);
    } else if (map[i]->type == 4)
        return_val = is_pad(global, map, i);
    if (return_val == 0)
        return (0);
    if (map[i]->type == 6)
        finish_game(window, global, map, i);
    return (2);
}

int is_collision(sfRenderWindow *window, global_t *global, game_object_t **map)
{
    int result = 0;

    if (global->player->pos.y < -global->player->rect.height ||
    global->player->pos.y > HEIGHT_SIZE)
        return (1);
    for (int i = 0; i < (global->len * global->col - global->air - 1); i++) {
        result = check_bloc_type(window, global, map, i);
        if (result == 1 || result == 0)
            return (result);
    }
    return (0);
}

void check_collision(sfRenderWindow *window, global_t *global, \
game_object_t **map_obj)
{
    sfFloatRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = WIDTH_SIZE;
    rect.height = HEIGHT_SIZE;
    if (is_collision(window, global, map_obj)) {
        do_in_collision(window, global, rect);
        global->status = 2;
    }
}
