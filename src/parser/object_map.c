/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

void init_player_two(global_t *global, int x, int y)
{
    sfIntRect rect = global->player->rect;

    global->x_player = x;
    global->y_player = y;
    global->player->pos.x = WIDTH_SIZE / 4 - rect.width / 2;
    global->player->pos.y = HEIGHT_SIZE / 2 - rect.height / 2;
    if (global->gravity < 0)
        global->gravity *= -1;
}

game_object_t *init_player(global_t *global, int x, int y, sfIntRect sprite)
{
    game_object_t *obj;
    if (global->nb_player == 0) {
        global->player = create_object("assets/player.png",
        create_vector2f(x, y), sprite);
    } else {
        global->player = create_object("assets/player2.png",
        create_vector2f(x, y), sprite);
    }
    obj = create_object("assets/blocs.png", create_vector2f(x, y),
    create_rect(0, 80, 0, 80));
    obj->type = 0;
    init_player_two(global, x, y);
    sfSprite_setPosition(global->player->sprite, global->player->pos);
    global->player->is_jumping = 0;
    global->player->seconds = 0;
    return (obj);
}

void check_obj(game_object_t *obj, int *k)
{
    if (!obj)
        *k -= 1;
}

game_object_t **char_map_to_obj(global_t *global, int fd)
{
    game_object_t **obj;
    char **map;
    int k = 0;

    map = load_map(fd, global);
    get_nb_air(global, map);
    close(fd);
    obj = malloc(sizeof(game_object_t *) * (global->len * global->col - \
    global->air + 1));
    for (int i = 0; i < global->len; i++) {
        for (int j = 0; j < global->col; j++) {
            obj[k] = get_object_from_map(global, map[i][j], i, j);
            check_obj(obj[k], &k);
            k++;
        }
    }
    for (int i = 0; i < global->len; i++)
        free(map[i]);
    free(map);
    return (obj);
}
