/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

game_object_t *create_object(char const *path_to_spritesheet, \
sfVector2f pos, sfIntRect rect)
{
    game_object_t *obj;

    obj = malloc(sizeof(game_object_t));
    obj->texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    obj->sprite = sfSprite_create();
    if (!obj->texture || !obj->sprite)
        return (NULL);
    obj->pos = pos;
    obj->rect = rect;
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    obj->type = 2;
    obj->alpha = 255;
    return (obj);
}

void destroy_object(game_object_t *obj)
{
    sfTexture_destroy(obj->texture);
    sfSprite_destroy(obj->sprite);
    free(obj);
}
