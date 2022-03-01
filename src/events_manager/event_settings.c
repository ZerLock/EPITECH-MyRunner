/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

void replace_good_sprite(global_t *global)
{
    if (global->nb_player == 0)
        global->player->texture =
        sfTexture_createFromFile("assets/player.png", NULL);
    else
        global->player->texture =
        sfTexture_createFromFile("assets/player2.png", NULL);
}

void is_back(global_t *global, sfEvent event, sfFloatRect back_rect,
sfVector2i tmp)
{
    if (sfFloatRect_contains(&back_rect, (float) tmp.x, (float) tmp.y)) {
        sfSprite_setColor(global->opt.back->sprite, create_color(99, 99, 99));
        if (event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&back_rect, (float) event.mouseButton.x,
        (float) event.mouseButton.y)) {
            global->status = 0;
            sfSound_play(global->beep);
            replace_good_sprite(global);
            sfSprite_setTexture(global->player->sprite,
            global->player->texture, sfTrue);
            sfSprite_setTextureRect(global->player->sprite,
            create_rect(0, 80, 0, 80));
        }
    } else
        sfSprite_setColor(global->opt.back->sprite, sfWhite);
}

void is_player_one(global_t *global, sfEvent event, sfFloatRect rect,
sfVector2i tmp)
{
    if (sfFloatRect_contains(&rect, (float) tmp.x, (float) tmp.y)) {
        if (event.mouseButton.button == sfMouseLeft &&
        event.type == sfEvtMouseButtonReleased &&
        sfFloatRect_contains(&rect, (float) event.mouseButton.x,
        (float) event.mouseButton.y)) {
            sfSound_play(global->beep);
            global->selector->pos.x = global->player->pos.x - 30;
            global->nb_player = 0;
            sfSprite_setPosition(global->selector->sprite,
            global->selector->pos);
        }
    }
}

void is_player_two(global_t *global, sfEvent event, sfFloatRect rect,
sfVector2i tmp)
{
    if (sfFloatRect_contains(&rect, (float) tmp.x, (float) tmp.y)) {
        if (event.mouseButton.button == sfMouseLeft &&
        event.type == sfEvtMouseButtonReleased &&
        sfFloatRect_contains(&rect, (float) event.mouseButton.x,
        (float) event.mouseButton.y)) {
            sfSound_play(global->beep);
            global->selector->pos.x = global->second_choice->pos.x - 30;
            global->nb_player = 1;
            sfSprite_setPosition(global->selector->sprite,
            global->selector->pos);
        }
    }
}

int get_event_opt(sfRenderWindow *window, global_t *global, sfEvent event)
{
    sfVector2i tmp = sfMouse_getPositionRenderWindow(window);
    sfFloatRect back_rect = sfSprite_getGlobalBounds(global->opt.back->sprite);
    sfFloatRect p_one = sfSprite_getGlobalBounds(global->player->sprite);
    sfFloatRect p_to = sfSprite_getGlobalBounds(global->second_choice->sprite);

    is_back(global, event, back_rect, tmp);
    is_player_one(global, event, p_one, tmp);
    is_player_two(global, event, p_to, tmp);
    return (0);
}
