/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

int print_helper(sfRenderWindow *window, global_t *global)
{
    sfRenderWindow_drawSprite(window, global->helper.background->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->opt.back->sprite, NULL);
    get_crosshair_position(window, global);
    sfRenderWindow_drawSprite(window, global->mouse->sprite, NULL);
    return (0);
}
