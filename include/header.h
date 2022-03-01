/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#ifndef HEADER_H_
    #define HEADER_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <time.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #define HEIGHT_SIZE  720
    #define WIDTH_SIZE 1280
    #define DIV_CLOCK   1000000.0
    #define BLOC_SIZE   80
    #define SPEED   7

typedef struct game_object {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    int speed;
    int is_jumping;
    int type;
    sfTime time;
    float seconds;
    int alpha;
} game_object_t;

typedef struct parallax {
    game_object_t *layer1;
    game_object_t *layer2;
} parallax_t;

typedef struct menu {
    game_object_t *play;
    game_object_t *quit;
    game_object_t *options;
    game_object_t *help;
    game_object_t *title;
} menu_t;

typedef struct gameover {
    game_object_t *title;
    game_object_t *menu;
    game_object_t *quit;
} gameover_t;

typedef struct opt {
    game_object_t *back;
    game_object_t *title;
} opt_t;

typedef struct clock {
    sfClock *clock;
    sfClock *player;
    sfClock *pad;
    sfClock *cursor;
    sfClock *end;
    sfClock *principal;
    sfTime p_time;
    float seconds_p;
} clocks_t;

typedef struct score {
    sfText *score;
    sfText *text;
    sfFont *font;
    sfVector2f pos;
} score_t;

typedef struct helper {
    game_object_t *background;
} helper_t;

typedef struct global {
    game_object_t *layer1;
    game_object_t *layer2;
    game_object_t *animation;
    sfSoundBuffer *anim_buff;
    sfSound *anim_sound;
    menu_t menu;
    game_object_t *player;
    game_object_t *second_choice;
    int nb_player;
    int x_player;
    int y_player;
    game_object_t *selector;
    gameover_t over;
    game_object_t *end_title;
    int gravity;
    game_object_t *mouse;
    opt_t opt;
    sfMusic *menu_ogg;
    sfSoundBuffer *buffer;
    sfSoundBuffer *buff;
    sfSound *beep;
    sfSound *jump;
    score_t score;
    helper_t helper;
    int status;
    clocks_t clocks;
    sfTime time;
    float seconds;
    int len;
    int col;
    int air;
    sfView *view;
    int x_view;
} global_t;

/* display_manager/main_print_manager.c */
int what_print(sfRenderWindow *window, global_t *global, game_object_t **map);
void update_animation(global_t *global);

/* display_manager/menu_printer.c */
int print_menu(sfRenderWindow *window, global_t *global);

/* display_manager/options_print.c */
int print_options(sfRenderWindow *window, global_t *global);

/* display_manager/print_gameover */
void print_finish(sfRenderWindow *window, global_t *global);
void print_gameover(sfRenderWindow *window, global_t *global);

/* display_manager/print_helper.c */
int print_helper(sfRenderWindow *window, global_t *global);

/* display_manager/game_printer.c */
int print_game(sfRenderWindow *window, global_t *global, game_object_t **map);

/* display_manager/parallax.c */
int print_background(sfRenderWindow *window, global_t *global);

/* events_manager/events_menu.c */
void get_crosshair_position(sfRenderWindow *window, global_t *global);
sfColor create_color(int r, int g, int b);
int get_event_menu(sfRenderWindow *window, sfEvent event, global_t *global);

/* event_manager/event_menu_two.c */
void do_before_options(global_t *global);
void is_option(sfFloatRect opt_rect, sfVector2f pos, sfEvent event, \
global_t *global);

/* event_manager/event_help.c */
int get_event_helper(sfRenderWindow *window, global_t *global, sfEvent event);

/* event_manager/event_gameover.c */
int get_event_gameover(sfRenderWindow *window, sfEvent event, \
global_t *global);

/* event_manager/event_game.c */
void check_player_rotation(global_t *global);
int get_event_game(sfRenderWindow *window, global_t *global, sfEvent event);

/* game_manager/game.c */
int game_loop(char const *path, sfRenderWindow *window);

/* game_manager/animations.c */
int animate_player(global_t *global);
int animate_mouse(global_t *global);
void set_clocks(global_t *global);

/* game_manager/background.c */
void move_background(global_t *global);

int check_air(char c);
void get_nb_air(global_t *global, char **map);
game_object_t *init_player(global_t *global, int x, int y, sfIntRect sprite);

/* parser/map_parser.c */
int open_file(char const *path);
int get_params(int fd);
int error_handling_map(int fd, int len);
void check_number(char **map_loaded, game_object_t *map, int i, int j);
char **load_map(int fd, global_t *global);

/* parser/object_map.c */
game_object_t *get_object_from_map(global_t *global, char c, int i, int j);
game_object_t **char_map_to_obj(global_t *global, int fd);

/* event_manager/event_settings.c */
int get_event_opt(sfRenderWindow *window, global_t *global, sfEvent event);

/* collisions/collisions.c */
int check_bloc_type(sfRenderWindow *window, global_t *global, \
game_object_t **map, int i);
int is_collision(sfRenderWindow *window, global_t *global, \
game_object_t **map);
void check_collision(sfRenderWindow *window, global_t *global, \
game_object_t **map_obj);

/* collisions/gravity.c */
int check_gravity_up(global_t *global, game_object_t **map, int i);
int check_gravity_down(global_t *global, game_object_t **map, int i);
int check_collisions_gravity(global_t *global, game_object_t **map, int i);
int check_gravity(global_t *global, game_object_t **map);

/* collisions/do_collisions.c */
void do_on_pad(global_t *global);
int finish_game(sfRenderWindow *window, global_t *global, \
game_object_t **map, int i);
int do_in_collision(sfRenderWindow *window, global_t *global, \
sfFloatRect rect);

/* utils/gameobject.c */
game_object_t *create_object(char const *path_to_spritesheet, \
sfVector2f pos, sfIntRect rect);
void destroy_object(game_object_t *obj);

/* utils/global.c */
void init_sound(char const *path, global_t *global);
void init_global_two(sfRenderWindow *window, global_t *global, int fd);
int initialize_global(sfRenderWindow *window, global_t *global, int fd);
int init_score(global_t *global);
int init_animation(global_t *global);

/* utils/destroyers.c */
void destroy_global_two(global_t *global);
void destroy_global(global_t *global, game_object_t **map);
void destroy_map_obj(global_t *global, game_object_t **map);

/* utils/part_init.c */
int init_clocks(global_t *global);
int init_options_var(global_t *global);
int init_parallax_background(global_t *global);
int init_menu_var(global_t *global);
int init_gameover_var(global_t *global);

/* utils/vector.c */
sfVector2f create_vector2f(float x, float y);

/* utils/create_color.c */
sfColor create_color(int r, int g, int b);

/* utils/crosshair.c */
void get_crosshair_position(sfRenderWindow *window, global_t *global);

/* utils/rect.c */
sfIntRect create_rect(int top, int height, int left, int width);
sfFloatRect create_frect(float top, float height, float left, float width);

/* utils/my_strcmp.c */
int my_strcmp(char const *s1, char const *s2);

/* utils/my_getnbr.c */
int my_getnbr(char const *str);

/* utils/int_to_string.c */
char *int_to_string(unsigned int nb);

#endif /* HEADER_H_ */
