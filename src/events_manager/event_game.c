/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

void check_player_rotation(global_t *global)
{
    if (global->gravity < 0) {
        sfSprite_setScale(global->player->sprite, (sfVector2f) {1, -1});
        sfSprite_setOrigin(global->player->sprite, (sfVector2f) {0, 80});
    } else if (global->gravity > 0) {
        sfSprite_setScale(global->player->sprite, (sfVector2f) {1, 1});
        sfSprite_setOrigin(global->player->sprite, (sfVector2f) {0, 0});
    }
}

void change_game_status_on_pause(global_t *global)
{
    if (global->status == 1) {
        global->status = 6;
        sfMusic_pause(global->menu_ogg);
    } else if (global->status == 6) {
        global->status = 1;
        sfMusic_play(global->menu_ogg);
    }
}

int get_event_game(sfRenderWindow *window, global_t *global, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeySpace && global->player->is_jumping == 0 &&
        global->status == 1) {
            global->player->is_jumping = 1;
            global->gravity *= -1;
            check_player_rotation(global);
            sfSound_play(global->jump);
        }
        if (event.key.code == sfKeyP)
            change_game_status_on_pause(global);
    }
    return (0);
}
