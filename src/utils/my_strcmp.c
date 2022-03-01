/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** Make a runner game
*/

#include "header.h"

int my_strcmp(char const *s1, char const *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return (0);
    if (*s1 > *s2)
        return (*s1 - *s2);
    if (*s1 < *s2)
        return (*s1 - *s2);
    if (*s1 == *s2)
        return my_strcmp(s1 + 1, s2 + 1);
    return (0);
}
