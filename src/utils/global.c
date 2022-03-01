/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

void init_sound(char const *path, global_t *global)
{
    global->buffer = sfSoundBuffer_createFromFile(path);
    global->beep = sfSound_create();

    sfSound_setBuffer(global->beep, global->buffer);
    init_animation(global);
}

void init_global_two(sfRenderWindow *window, global_t *global, int fd)
{
    global->seconds = 0;
    global->view = sfView_create();
    global->view = sfView_createFromRect(create_frect(0, 720, 0, 1280));
    global->x_view = 0;
    global->nb_player = 0;
    global->second_choice = create_object("assets/player2.png",
    (sfVector2f) {WIDTH_SIZE - WIDTH_SIZE / 3 + 80 / 2, \
    HEIGHT_SIZE / 2 - 80 / 2}, create_rect(0, 80, 0, 80));
    global->player = NULL;
    global->selector = create_object("assets/selector.png",
    (sfVector2f) {WIDTH_SIZE / 4 - 80 / 2 - 30,
    HEIGHT_SIZE / 2 - 80 / 2 - 30}, create_rect(0, 140, 0, 140));
    global->mouse = create_object("assets/cursor.png",
    (sfVector2f) {0, 0}, create_rect(0, 50, 0, 50));
    global->mouse->seconds = 0;
    global->menu_ogg = sfMusic_createFromFile("assets/sounds/menu.ogg");
    sfMusic_setLoop(global->menu_ogg, sfTrue);
    init_sound("assets/sounds/beep.wav", global);
    global->gravity = 60;
    global->jump = sfSound_create();
}

int init_animation(global_t *global)
{
    global->animation = create_object("assets/copyright.png",
    create_vector2f(0, 0), create_rect(0, HEIGHT_SIZE, 0, WIDTH_SIZE));
    global->anim_buff =
    sfSoundBuffer_createFromFile("assets/sounds/copyright.ogg");
    global->anim_sound = sfSound_create();
    sfSound_setBuffer(global->anim_sound, global->anim_buff);
    global->end_title = create_object("assets/end_title.png",
    create_vector2f(0, 0), create_rect(0, HEIGHT_SIZE, 0, WIDTH_SIZE));
    return (0);
}

int initialize_global(sfRenderWindow *window, global_t *global, int fd)
{
    global->len = get_params(fd);
    global->col = get_params(fd);
    if (global->len != 9 || global->col <= 0) {
        write(2, "bad map format !\n", 17);
        return (84);
    }
    if (init_parallax_background(global) == 84 || init_menu_var(global) == 84
    || init_options_var(global) == 84 || init_score(global) == 84)
        return (84);
    init_clocks(global);
    init_global_two(window, global, fd);
    global->buff = sfSoundBuffer_createFromFile("assets/sounds/jump.wav");
    sfSound_setBuffer(global->jump, global->buff);
    init_gameover_var(global);
    global->helper.background = create_object("assets/helper.png",
    create_vector2f(0, 0), create_rect(0, HEIGHT_SIZE, 0, WIDTH_SIZE));
    sfMusic_setVolume(global->menu_ogg, 150.0f);
    sfRenderWindow_setView(window, global->view);
    return (0);
}

int init_score(global_t *global)
{
    global->score.font = sfFont_createFromFile("assets/fonts/caladea.ttf");
    global->score.text = sfText_create();
    global->score.score = sfText_create();
    sfText_setFont(global->score.text, global->score.font);
    sfText_setFont(global->score.score, global->score.font);
    sfText_setString(global->score.score, "Score: ");
    sfText_setString(global->score.text, "0");
    sfText_setCharacterSize(global->score.text, 50);
    sfText_setCharacterSize(global->score.score, 50);
    global->score.pos.x = 10;
    global->score.pos.y = 5;
    sfText_setPosition(global->score.score, (sfVector2f) {WIDTH_SIZE / 2,
    HEIGHT_SIZE / 3});
    sfText_setPosition(global->score.text, global->score.pos);
    if (!global->score.text || !global->score.font)
        return (84);
    return (0);
}
