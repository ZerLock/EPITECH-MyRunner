/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

void print_animation(sfRenderWindow *window, global_t *global)
{
    sfRenderWindow_drawSprite(window, global->animation->sprite, NULL);
}

void update_animation(global_t *global)
{
    sfColor color = {255, 255, 255, 255};

    global->animation->alpha -= 2;
    color.a = global->animation->alpha;
    sfSprite_setColor(global->animation->sprite, color);
    if (global->animation->alpha <= 0) {
        global->status = 0;
        sfMusic_play(global->menu_ogg);
    }
}

int what_print(sfRenderWindow *window, global_t *global, game_object_t **map)
{
    if (global->status < 0)
        print_animation(window, global);
    if (global->status == 0)
        print_menu(window, global);
    if (global->status == 1 || global->status == 6)
        print_game(window, global, map);
    if (global->status == 2)
        print_gameover(window, global);
    if (global->status == 3)
        print_options(window, global);
    if (global->status == 4)
        print_helper(window, global);
    if (global->status == 5)
        print_finish(window, global);
    return (0);
}
