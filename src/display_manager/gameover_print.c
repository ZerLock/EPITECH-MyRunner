/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

void print_finish(sfRenderWindow *window, global_t *global)
{
    sfRenderWindow_drawSprite(window, global->end_title->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->over.quit->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->over.menu->sprite, NULL);
    get_crosshair_position(window, global);
    sfRenderWindow_drawText(window, global->score.score, NULL);
    sfRenderWindow_drawText(window, global->score.text, NULL);
    sfRenderWindow_drawSprite(window, global->mouse->sprite, NULL);
}

void print_gameover(sfRenderWindow *window, global_t *global)
{
    sfSprite_setPosition(global->over.title->sprite, global->over.title->pos);
    sfRenderWindow_drawSprite(window, global->over.title->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->over.quit->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->over.menu->sprite, NULL);
    get_crosshair_position(window, global);
    sfRenderWindow_drawText(window, global->score.score, NULL);
    sfRenderWindow_drawText(window, global->score.text, NULL);
    sfRenderWindow_drawSprite(window, global->mouse->sprite, NULL);
}
