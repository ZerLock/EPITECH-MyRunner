/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

void destroy_global_two(global_t *global)
{
    destroy_object(global->layer1);
    destroy_object(global->layer2);
    destroy_object(global->menu.play);
    destroy_object(global->menu.options);
    destroy_object(global->menu.quit);
    destroy_object(global->menu.title);
    destroy_object(global->over.menu);
    destroy_object(global->over.quit);
    destroy_object(global->over.title);
    destroy_object(global->opt.back);
    destroy_object(global->opt.title);
    destroy_object(global->selector);
    sfClock_destroy(global->clocks.clock);
    sfClock_destroy(global->clocks.pad);
    sfClock_destroy(global->clocks.end);
    sfClock_destroy(global->clocks.cursor);
    sfClock_destroy(global->clocks.player);
    sfClock_destroy(global->clocks.principal);
    sfView_destroy(global->view);
    destroy_object(global->mouse);
}

void destroy_global(global_t *global, game_object_t **map)
{
    destroy_global_two(global);
    sfFont_destroy(global->score.font);
    sfText_destroy(global->score.text);
    sfText_destroy(global->score.score);
    destroy_object(global->second_choice);
    if (global->player != NULL)
        destroy_object(global->player);
    sfMusic_destroy(global->menu_ogg);
    sfSound_destroy(global->beep);
    sfSound_destroy(global->jump);
    sfSound_destroy(global->anim_sound);
    sfSoundBuffer_destroy(global->buffer);
    sfSoundBuffer_destroy(global->buff);
    sfSoundBuffer_destroy(global->anim_buff);
    destroy_map_obj(global, map);
    free(global);
}

void destroy_map_obj(global_t *global, game_object_t **map)
{
    int i;

    for (i = 0; i < (global->len * global->col - global->air); i++)
        destroy_object(map[i]);
    free(map);
}
