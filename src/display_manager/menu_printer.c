/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

int print_menu(sfRenderWindow *window, global_t *global)
{
    sfRenderWindow_drawSprite(window, global->menu.title->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->menu.play->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->menu.options->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->menu.quit->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->menu.help->sprite, NULL);
    get_crosshair_position(window, global);
    sfRenderWindow_drawSprite(window, global->mouse->sprite, NULL);
    return (0);
}
