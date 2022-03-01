/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

void reset_game(global_t *global)
{
    sfSound_play(global->beep);
    global->status = 1;
    global->score.pos.x = 10;
    global->score.pos.y = 5;
    sfText_setPosition(global->score.text, global->score.pos);
    sfSprite_setColor(global->menu.play->sprite, sfWhite);
    global->player->pos.x = global->x_player;
    global->player->pos.y = global->y_player;
    if (global->gravity < 0)
        global->gravity *= -1;
    sfSprite_setPosition(global->player->sprite, global->player->pos);
    sfClock_restart(global->clocks.principal);
}

void is_play(sfFloatRect rect, sfVector2f pos, sfEvent event,
global_t *global)
{
    if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
        sfSprite_setColor(global->menu.play->sprite, create_color(99, 99, 99));
        if (event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&rect, event.mouseButton.x, event.mouseButton.y))
            reset_game(global);
    } else
        sfSprite_setColor(global->menu.play->sprite, sfWhite);
}

int is_quit(sfFloatRect rect, sfVector2f pos, sfEvent event,
global_t *global)
{
    if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
        sfSprite_setColor(global->menu.quit->sprite, create_color(99, 99, 99));
        if (event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&rect, event.mouseButton.x,
        event.mouseButton.y)) {
            sfSound_play(global->beep);
            return (1);
        }
    } else
        sfSprite_setColor(global->menu.quit->sprite, sfWhite);
    return (0);
}

void is_helper(sfFloatRect rect, sfVector2f pos, sfEvent event,
global_t *global)
{
    if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
        sfSprite_setColor(global->menu.help->sprite, create_color(99, 99, 99));
        if (event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&rect, event.mouseButton.x,
        event.mouseButton.y)) {
            sfSound_play(global->beep);
            global->status = 4;
            sfSprite_setColor(global->menu.help->sprite, sfWhite);
        }
    } else
        sfSprite_setColor(global->menu.help->sprite, sfWhite);
}

int get_event_menu(sfRenderWindow *window, sfEvent event, global_t *global)
{
    sfVector2i tmp = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos;
    sfFloatRect p_rect = sfSprite_getGlobalBounds(global->menu.play->sprite);
    sfFloatRect q_rect = sfSprite_getGlobalBounds(global->menu.quit->sprite);
    sfFloatRect o_r = sfSprite_getGlobalBounds(global->menu.options->sprite);
    sfFloatRect h_rect = sfSprite_getGlobalBounds(global->menu.help->sprite);

    pos.x = tmp.x;
    pos.y = tmp.y;
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
    }
    is_play(p_rect, pos, event, global);
    if (is_quit(q_rect, pos, event, global))
        sfRenderWindow_close(window);
    is_option(o_r, pos, event, global);
    is_helper(h_rect, pos, event, global);
    return (0);
}
