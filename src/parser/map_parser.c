/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

int open_file(char const *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (84);
    return (fd);
}

int get_params(int fd)
{
    int nb_lines;
    char *buff = malloc(sizeof(char) * 12);
    char tmp;
    int i = 0;

    do {
        nb_lines = read(fd, &tmp, 1);
        if (nb_lines <= 0)
            return (-1);
        buff[i] = tmp;
        i++;
        if (i == 12)
            return (-1);
    } while (tmp != '\n' && tmp != '\0');
    buff[i] = '\0';
    nb_lines = my_getnbr(buff);
    free(buff);
    if (nb_lines <= 0)
        return (-1);
    return (nb_lines);
}

int error_handling_map(int fd, int len)
{
    if (len != 9)
        return (84);
    return (0);
}

char **load_map(int fd, global_t *global)
{
    char **map;

    map = malloc(sizeof(char *) * global->len + 1);
    for (int i = 0; i < global->len; i++) {
        map[i] = malloc(sizeof(char) * global->col + 3);
        read(fd, map[i], global->col + 1);
    }
    return (map);
}
