/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

void get_crosshair_position(sfRenderWindow *window, global_t *global)
{
    sfVector2i tmp;

    tmp = sfMouse_getPositionRenderWindow(window);
    global->mouse->pos.x = (float) tmp.x - global->mouse->rect.width / 2;
    global->mouse->pos.y = (float) tmp.y - global->mouse->rect.height / 2;
    sfSprite_setPosition(global->mouse->sprite, global->mouse->pos);
}
