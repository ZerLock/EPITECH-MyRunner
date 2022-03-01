/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

int get_event_helper(sfRenderWindow *window, global_t *global, sfEvent event)
{
    sfVector2i tmp = sfMouse_getPositionRenderWindow(window);
    sfFloatRect rect = sfSprite_getGlobalBounds(global->opt.back->sprite);

    if (sfFloatRect_contains(&rect, (float) tmp.x, (float) tmp.y)) {
        sfSprite_setColor(global->opt.back->sprite, create_color(99, 99, 99));
        if (event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&rect, (float) event.mouseButton.x,
        (float) event.mouseButton.y)) {
            global->status = 0;
            sfSound_play(global->beep);
        }
    } else
        sfSprite_setColor(global->opt.back->sprite, sfWhite);
    return (0);
}
