/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

int is_quit_over(global_t *global, sfEvent event, sfFloatRect quit, \
sfVector2f pos)
{
    if (sfFloatRect_contains(&quit, pos.x, pos.y)) {
        sfSprite_setColor(global->over.quit->sprite, create_color(99, 99, 99));
        if (event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&quit, event.mouseButton.x,
        event.mouseButton.y) && event.type == sfEvtMouseButtonReleased) {
            sfSound_play(global->beep);
            return (1);
        }
    } else
        sfSprite_setColor(global->over.quit->sprite, sfWhite);
    return (0);
}

void is_menu(global_t *global, sfEvent event, sfFloatRect menu, \
sfVector2f pos)
{
    if (sfFloatRect_contains(&menu, pos.x, pos.y)) {
        sfSprite_setColor(global->over.menu->sprite, create_color(99, 99, 99));
        if (event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&menu, event.mouseButton.x,
        event.mouseButton.y) && event.type == sfEvtMouseButtonReleased) {
            sfSound_play(global->beep);
            global->status = 0;
            sfView_move(global->view, create_vector2f(global->x_view, 0));
            global->x_view = 0;
            sfMusic_play(global->menu_ogg);
        }
    } else
        sfSprite_setColor(global->over.menu->sprite, sfWhite);
}

int get_event_gameover(sfRenderWindow *window, sfEvent event, global_t *global)
{
    sfVector2i tmp = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = {tmp.x, tmp.y};
    sfFloatRect menu = sfSprite_getGlobalBounds(global->over.menu->sprite);
    sfFloatRect quit = sfSprite_getGlobalBounds(global->over.quit->sprite);

    is_menu(global, event, menu, pos);
    if (is_quit_over(global, event, quit, pos))
        sfRenderWindow_close(window);
    return (0);
}
