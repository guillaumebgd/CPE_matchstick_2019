/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** returns nb from a str returns 0 if error
*/

#include "my.h"

static int get_sign(const char *str, int *index)
{
    int neg = 1;

    while (str[(*index)] && (str[(*index)] == '+' || str[(*index)] == '-')) {
        if (str[(*index)] == '-')
            neg *= -1;
        (*index) += 1;
    }
    return (neg);
}

int my_getnbr(const char *str)
{
    int index = 0;
    int neg = 1;
    int nb = 0;

    neg = get_sign(str, &index);
    while (str[index] && str[index] == ' ')
        index += 1;
    if (my_strcmp("2147483647", &str[index]) < 0)
        return (0);
    while (str[index] && my_isnum(str[index])) {
        if (index > 0)
            nb *= 10;
        nb += str[index] - 48;
        index += 1;
    }
    return (nb * neg);
}