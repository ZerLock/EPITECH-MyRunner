/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

void move_background(global_t *global)
{
    if (global->status != 1)
        sfSprite_move(global->layer1->sprite, (sfVector2f) {-SPEED * 0.2, 0});
    else
        sfSprite_move(global->layer1->sprite, create_vector2f(SPEED * 0.2, 0));
    global->layer1->pos = sfSprite_getPosition(global->layer1->sprite);
    if (global->layer1->pos.x <= global->x_view - WIDTH_SIZE) {
        global->layer1->pos.x = global->x_view;
        sfSprite_setPosition(global->layer1->sprite, global->layer1->pos);
    }
    if (global->status != 1)
        sfSprite_move(global->layer2->sprite, (sfVector2f) {-SPEED * 0.5, 0});
    else
        sfSprite_move(global->layer2->sprite, create_vector2f(SPEED * 0.5, 0));
    global->layer2->pos = sfSprite_getPosition(global->layer2->sprite);
    if (global->layer2->pos.x <= global->x_view - WIDTH_SIZE) {
        global->layer2->pos.x = global->x_view;
        sfSprite_setPosition(global->layer2->sprite, global->layer2->pos);
    }
}
