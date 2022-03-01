/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

int print_background(sfRenderWindow *window, global_t *global)
{
    sfRenderWindow_drawSprite(window, global->layer1->sprite, NULL);
    sfSprite_move(global->layer1->sprite, create_vector2f(WIDTH_SIZE, 0));
    sfRenderWindow_drawSprite(window, global->layer1->sprite, NULL);
    sfSprite_move(global->layer1->sprite, create_vector2f(-WIDTH_SIZE, 0));
    sfRenderWindow_drawSprite(window, global->layer2->sprite, NULL);
    sfSprite_move(global->layer2->sprite, create_vector2f(WIDTH_SIZE, 0));
    sfRenderWindow_drawSprite(window, global->layer2->sprite, NULL);
    sfSprite_move(global->layer2->sprite, create_vector2f(-WIDTH_SIZE, 0));
    return (0);
}
