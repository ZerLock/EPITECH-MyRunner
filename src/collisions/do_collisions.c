/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

void do_on_pad(global_t *global)
{
    sfSound_play(global->jump);
    global->gravity *= -1;
    check_player_rotation(global);
    global->player->pos.y += BLOC_SIZE * (BLOC_SIZE / global->gravity);
}

int finish_game(sfRenderWindow *window, global_t *global, \
game_object_t **map, int i)
{
    sfFloatRect rect = {0, 0, WIDTH_SIZE, HEIGHT_SIZE};

    if (global->player->pos.x < map[i]->pos.x + map[i]->rect.width - \
    map[i]->rect.width/2 && global->player->pos.x + \
    global->player->rect.width > map[i]->pos.x + map[i]->rect.width/2 &&
    global->player->pos.y < map[i]->pos.y + map[i]->rect.height &&
    global->player->pos.y + global->player->rect.height > map[i]->pos.y) {
        do_in_collision(window, global, rect);
        global->status = 5;
        return (1);
    }
    return (0);
}

int do_in_collision(sfRenderWindow *window, global_t *global, sfFloatRect rect)
{
    global->layer1->pos.x = 0;
    global->layer2->pos.x = 0;
    sfSprite_setPosition(global->layer1->sprite, global->layer1->pos);
    sfSprite_setPosition(global->layer2->sprite, global->layer2->pos);
    sfView_reset(global->view, rect);
    sfRenderWindow_setView(window, global->view);
    global->x_view = 0;
    global->player->pos.x = WIDTH_SIZE / 4 - global->player->rect.width / 2;
    global->player->pos.y = HEIGHT_SIZE / 2 - global->player->rect.height / 2;
    if (global->gravity < 0)
        global->gravity *= -1;
    sfSprite_setPosition(global->player->sprite, global->player->pos);
    sfMusic_pause(global->menu_ogg);
    rect = sfText_getGlobalBounds(global->score.score);
    global->score.pos.x = WIDTH_SIZE / 2 + rect.width + 10;
    global->score.pos.y = HEIGHT_SIZE / 3;
    sfText_setPosition(global->score.text, global->score.pos);
    return (0);
}
