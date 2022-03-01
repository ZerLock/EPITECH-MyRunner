/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

int init_clocks(global_t *global)
{
    global->clocks.clock = sfClock_create();
    global->clocks.player = sfClock_create();
    global->clocks.pad = sfClock_create();
    global->clocks.cursor = sfClock_create();
    global->clocks.end = sfClock_create();
    global->clocks.principal = sfClock_create();
    return (0);
}

int init_options_var(global_t *global)
{
    int x_mid = WIDTH_SIZE / 2;
    sfIntRect rect = create_rect(0, 80, 480, 80);

    global->opt.back = create_object("assets/blocs.png",
    (sfVector2f) {10, 10}, rect);
    global->opt.title = create_object("assets/options.png",
    (sfVector2f) {x_mid - 300, 50}, create_rect(0, 90, 0, 600));
    if (global->opt.back == NULL || global->opt.title == NULL)
        return (84);
    return (0);
}

int init_parallax_background(global_t *global)
{
    sfIntRect screen = create_rect(0, 720, 0, 1280);

    global->layer1 = create_object("assets/parallax_background/layer1.png",
    create_vector2f(0, 0), screen);
    global->layer2 = create_object("assets/parallax_background/layer2.png",
    create_vector2f(0, 0), screen);
    global->status = -1;
    if (global->layer1 == NULL || global->layer2 == NULL)
        return (84);
    return (0);
}

int init_menu_var(global_t *global)
{
    int x_mid = WIDTH_SIZE / 2;
    int y_mid = HEIGHT_SIZE / 2;
    global->menu.play = create_object("assets/button.png",
    create_vector2f(x_mid - 250 / 2, y_mid - 120 - 100 / 2),
    create_rect(0, 100, 500, 250));
    global->menu.quit = create_object("assets/button.png",
    create_vector2f(x_mid - 250 / 2, y_mid + 120 - 100 / 2),
    create_rect(0, 100, 750, 250));
    global->menu.options = create_object("assets/button.png",
    create_vector2f(x_mid - 250 / 2, y_mid - 100 / 2),
    create_rect(0, 100, 0, 250));
    global->menu.title = create_object("assets/title.png",
    create_vector2f(x_mid - 600 / 2, 50), create_rect(0, 90, 0, 600));
    global->menu.help = create_object("assets/blocs.png",
    create_vector2f(WIDTH_SIZE - 90, 10), create_rect(0, 80, 560, 80));
    if (!global->menu.play || !global->menu.quit ||
    !global->menu.title || !global->menu.options ||
    !global->menu.help)
        return (84);
    return (0);
}

int init_gameover_var(global_t *global)
{
    int x_mid = WIDTH_SIZE / 2;
    int y_mid = HEIGHT_SIZE / 2;

    global->over.title = create_object("assets/gameover.png",
    create_vector2f(x_mid - 600 / 2, 50), create_rect(0, 90, 0, 600));
    global->over.quit = create_object("assets/button.png",
    create_vector2f(x_mid / 4, y_mid + 100 / 2 + 10),
    create_rect(0, 100, 750, 250));
    global->over.menu = create_object("assets/button.png",
    create_vector2f(x_mid / 4, y_mid - 100 / 2 - 10),
    create_rect(0, 100, 250, 250));
    return (0);
}
