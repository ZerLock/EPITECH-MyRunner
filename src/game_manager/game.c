/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

int get_event(sfRenderWindow *window, sfEvent event, global_t *global)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (global->status == 0)
            get_event_menu(window, event, global);
        if (global->status == 1 || global->status == 6)
            get_event_game(window, global, event);
        if (global->status == 2 || global->status == 5)
            get_event_gameover(window, event, global);
        if (global->status == 3)
            get_event_opt(window, global, event);
        if (global->status == 4)
            get_event_helper(window, global, event);
    }
    return (0);
}

void is_game(sfRenderWindow *window, global_t *global, game_object_t **map_obj)
{
    char *score;

    if (global->status == 1) {
        sfView_move(global->view, create_vector2f(SPEED, 0));
        sfRenderWindow_setView(window, global->view);
        global->player->pos.x += SPEED;
        sfSprite_move(global->player->sprite, create_vector2f(SPEED, 0));
        global->x_view += SPEED;
        global->score.pos.x += SPEED;
        sfText_setPosition(global->score.text, global->score.pos);
        score = int_to_string((int) global->clocks.seconds_p);
        if (score == NULL) {
            score[0] = '0';
            score[1] = '\n';
        }
        sfText_setString(global->score.text, score);
        free(score);
        check_collision(window, global, map_obj);
        check_gravity(global, map_obj);
    }
}

void update(sfRenderWindow *window, global_t *global, game_object_t **map_obj)
{
    sfRenderWindow_clear(window, sfBlack);
    if (global->status >= 0)
        print_background(window, global);
    else
        update_animation(global);
    if (global->player->seconds > 1.0 / 2) {
        animate_player(global);
        sfClock_restart(global->clocks.player);
    }
    if (global->status != 1 && global->mouse->seconds > 1.0 / 15.0) {
        animate_mouse(global);
        sfClock_restart(global->clocks.cursor);
    }
    if (global->seconds >= 1 / 240.0) {
        move_background(global);
        is_game(window, global, map_obj);
        sfClock_restart(global->clocks.clock);
    }
    what_print(window, global, map_obj);
    sfRenderWindow_display(window);
}

int check_player_pos(global_t *global, game_object_t **map)
{
    if (global->player == NULL) {
        write(2, "bad map format !\n", 17);
        destroy_global(global, map);
        return (84);
    }
    return (0);
}

int game_loop(char const *path, sfRenderWindow *window)
{
    sfEvent event;
    global_t *global = malloc(sizeof(global_t));
    game_object_t **map_obj;
    int fd = open(path, O_RDONLY);

    if (initialize_global(window, global, fd) == 84)
        return (84);
    map_obj = char_map_to_obj(global, fd);
    if (!map_obj)
        return (84);
    if (check_player_pos(global, map_obj) == 84)
        return (84);
    sfSound_play(global->anim_sound);
    while (sfRenderWindow_isOpen(window)) {
        set_clocks(global);
        get_event(window, event, global);
        update(window, global, map_obj);
    }
    destroy_global(global, map_obj);
    return (0);
}
