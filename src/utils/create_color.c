/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

sfColor create_color(int r, int g, int b)
{
    sfColor color;

    color.r = r;
    color.g = g;
    color.b = b;
    color.a = 255;
    return (color);
}
