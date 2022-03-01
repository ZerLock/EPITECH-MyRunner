/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

void print_help(void)
{
    int fd;
    char *buffer;
    int buf_size = 32;
    int len = buf_size;

    buffer = malloc(sizeof(char) * buf_size);
    fd = open("help_me.txt", O_RDONLY);
    while (len > 0) {
        len = read(fd, buffer, buf_size - 1);
        write(1, buffer, len);
    }
    close(fd);
}

void print_bad_args(void)
{
    write(1, "./my_runner: bad arguments: 0 given but 1 is required\n", 54);
    write(1, "retry with -h\n", 14);
}

int main(int ac, char **av)
{
    sfVideoMode mode = {WIDTH_SIZE, HEIGHT_SIZE, 32};
    sfRenderWindow *window;
    char *title = "Runner Beats";

    if (ac == 2) {
        if (my_strcmp(av[1], "-h") == 0)
            print_help();
        else {
            window = sfRenderWindow_create(mode, title, sfDefaultStyle, NULL);
            sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
            sfRenderWindow_setFramerateLimit(window, 60);
            sfRenderWindow_setMouseCursorVisible(window, sfFalse);
            game_loop(av[1], window);
        }
    } else {
        print_bad_args();
        return (84);
    }
    sfRenderWindow_destroy(window);
    return (0);
}
