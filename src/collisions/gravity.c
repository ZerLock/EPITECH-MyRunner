/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

int check_gravity_top(global_t *global, game_object_t **map, int i)
{
    if (global->player->pos.x + global->player->rect.width > map[i]->pos.x &&
    global->player->pos.x < map[i]->pos.x + map[i]->rect.width &&
    global->player->pos.y + global->gravity < map[i]->pos.y + \
    map[i]->rect.height && global->player->pos.y + \
    global->player->rect.height > map[i]->pos.y && global->gravity < 0 &&
    map[i]->type == 1) {
        global->player->pos.y = map[i]->pos.y + map[i]->rect.height;
        sfSprite_setPosition(global->player->sprite, global->player->pos);
        if (global->player->is_jumping == 1)
            global->player->is_jumping = 0;
        return (1);
    }
    return (0);
}

int check_gravity_down(global_t *global, game_object_t **map, int i)
{
    if (global->player->pos.x + global->player->rect.width > map[i]->pos.x &&
    global->player->pos.x < map[i]->pos.x + map[i]->rect.width &&
    global->player->pos.y < map[i]->pos.y + map[i]->rect.height &&
    global->player->pos.y + global->gravity + \
    global->player->rect.height > map[i]->pos.y && global->gravity > 0 &&
    map[i]->type == 1) {
        global->player->pos.y = map[i]->pos.y - global->player->rect.height;
        sfSprite_setPosition(global->player->sprite, global->player->pos);
        if (global->player->is_jumping == 1)
            global->player->is_jumping = 0;
        return (1);
    }
    return (0);
}

int check_collisions_gravity(global_t *global, game_object_t **map, int i)
{
    if (check_gravity_top(global, map, i))
        return (1);
    if (check_gravity_down(global, map, i))
        return (1);
    return (0);
}

int check_gravity(global_t *global, game_object_t **map)
{
    for (int i = 0; i < (global->len * global->col - global->air); i++) {
        if (check_collisions_gravity(global, map, i))
            return (1);
    }
    global->player->pos.y += global->gravity;
    sfSprite_setPosition(global->player->sprite, global->player->pos);
    return (0);
}
