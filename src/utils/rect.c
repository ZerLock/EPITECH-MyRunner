/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

sfIntRect create_rect(int top, int height, int left, int width)
{
    sfIntRect rect;

    rect.top = top;
    rect.height = height;
    rect.left = left;
    rect.width = width;
    return (rect);
}

sfFloatRect create_frect(float top, float height, float left, float width)
{
    sfFloatRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}
