/*
** EPITECH PROJECT, 2022
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

game_object_t *object_four(global_t *global, char c, int x, int y)
{
    game_object_t *obj;

    switch (c) {
    case '6':
        obj = create_object("assets/end_pad.png", create_vector2f(x, y + 50),
        create_rect(0, 30, 0, 80));
        obj->type = 6;
        obj->seconds = 0;
        break;
    case '7':
        obj = init_player(global, x, y, create_rect(0, 80, 0, 80));
        break;
    case '8':
        obj = create_object("assets/blocs.png", create_vector2f(x, y),
        create_rect(0, 80, 0, 80));
        break;
    }
    return (obj);
}

game_object_t *object_three(global_t *global, char c, int x, int y)
{
    game_object_t *obj;

    switch (c) {
    case '4':
        obj = create_object("assets/blocs.png", create_vector2f(x, y + 50),
        create_rect(50, 30, 320, 80));
        obj->type = 4;
        break;
    case '5':
        obj = create_object("assets/blocs.png", create_vector2f(x, y),
        create_rect(0, 30, 400, 80));
        obj->type = 4;
        break;
    default:
        obj = object_four(global, c, x, y);
        break;
    }
    return (obj);
}

game_object_t *object_two(global_t *global, char c, int x, int y)
{
    game_object_t *obj;

    switch (c) {
    case '2':
        obj = create_object("assets/blocs.png", create_vector2f(x, y),
        create_rect(0, 80, 160, 80));
        obj->type = 2;
        break;
    case '3':
        obj = create_object("assets/blocs.png", create_vector2f(x, y),
        create_rect(0, 80, 240, 80));
        obj->type = 3;
        break;
    default:
        obj = object_three(global, c, x, y);
        break;
    }
    return (obj);
}

game_object_t *get_object_from_map(global_t *global, char c, int i, int j)
{
    game_object_t *obj;
    int x = j * BLOC_SIZE;
    int y = i * BLOC_SIZE;

    switch (c) {
    case ' ':
        return (NULL);
        break;
    case '1':
        obj = create_object("assets/blocs.png", create_vector2f(x, y),
        create_rect(0, 80, 80, 80));
        obj->type = 1;
        break;
    default:
        obj = object_two(global, c, x, y);
        break;
    }
    return (obj);
}
