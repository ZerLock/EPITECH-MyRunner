/*
** EPITECH PROJECT, 2021
** int_to_binary
** File description:
** convert int to binary number
*/

#include "header.h"

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i]; i++);
    return (i);
}

char *my_revstr(char *str)
{
    int i;
    int j;
    char tmp;

    i = 0;
    j = my_strlen(str) - 1;
    while (i <= j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return (str);
}

char *int_to_string(unsigned int nb)
{
    char *str;
    int i;

    str = malloc(sizeof(char) * 34);
    for (i = 0; nb > 0; i++) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    str[i] = '\0';
    return (my_revstr(str));
}
