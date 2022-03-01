/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

int animate_player(global_t *global)
{
    switch (global->player->rect.left) {
    case 0:
    case 80:
    case 160:
        global->second_choice->rect.left += 80;
        global->player->rect.left += 80;
        break;
    case 240:
        global->second_choice->rect.left = 0;
        global->player->rect.left = 0;
        break;
    default:
        global->second_choice->rect.left = 0;
        global->player->rect.left = 0;
        break;
    }
    sfSprite_setTextureRect(global->player->sprite, global->player->rect);
    sfSprite_setTextureRect(global->second_choice->sprite,
    global->second_choice->rect);
    return (0);
}

int animate_mouse(global_t *global)
{
    switch (global->mouse->rect.left) {
    case 0:
    case 50:
    case 100:
        global->mouse->rect.left += 50;
        break;
    case 150:
        global->mouse->rect.left = 0;
        break;
    default:
        global->mouse->rect.left = 0;
        break;
    }
    sfSprite_setTextureRect(global->mouse->sprite, global->mouse->rect);
    return (0);
}

void set_clocks(global_t *global)
{
    global->time = sfClock_getElapsedTime(global->clocks.clock);
    global->seconds = global->time.microseconds / DIV_CLOCK;
    global->player->time = sfClock_getElapsedTime(global->clocks.player);
    global->player->seconds = global->player->time.microseconds / DIV_CLOCK;
    global->mouse->time = sfClock_getElapsedTime(global->clocks.cursor);
    global->mouse->seconds = global->mouse->time.microseconds / DIV_CLOCK;
    global->clocks.p_time = sfClock_getElapsedTime(global->clocks.principal);
    global->clocks.seconds_p = global->clocks.p_time.microseconds / DIV_CLOCK;
}
