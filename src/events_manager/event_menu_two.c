/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

void do_before_options(global_t *global)
{
    sfSound_play(global->beep);
    global->status = 3;
    global->player->texture =
    sfTexture_createFromFile("assets/player.png", NULL);
    sfSprite_setTexture(global->player->sprite,
    global->player->texture, sfTrue);
    sfSprite_setTextureRect(global->player->sprite,
    create_rect(0, 80, 0, 80));
    sfSprite_setColor(global->menu.options->sprite, sfWhite);
    global->player->pos.y = HEIGHT_SIZE / 2 -
    global->player->rect.height / 2;
    sfSprite_setPosition(global->player->sprite, global->player->pos);
    sfSprite_setScale(global->player->sprite, create_vector2f(1, 1));
    sfSprite_setOrigin(global->player->sprite, create_vector2f(0, 0));
}

void is_option(sfFloatRect opt_rect, sfVector2f pos, sfEvent event, \
global_t *global)
{
    if (sfFloatRect_contains(&opt_rect, pos.x, pos.y)) {
        sfSprite_setColor(global->menu.options->sprite,
        create_color(99, 99, 99));
        if (event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&opt_rect, event.mouseButton.x,
        event.mouseButton.y)) {
            do_before_options(global);
        }
    } else
        sfSprite_setColor(global->menu.options->sprite, sfWhite);
}
