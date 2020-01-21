/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** returns nb from a str returns 0 if error
*/

#include "my.h"

static int get_sign(const char *str, int *i)
{
    int neg = 1;

    while (str[(*i)] && (str[(*i)] == '+' || str[(*i)] == '-')) {
        if (str[(*i)] == '-')
            neg *= -1;
        (*i) += 1;
    }
    return (neg);
}

int my_getnbr(const char *str)
{
    int neg = 1;
    int nb = 0;
    int i = 0;

    neg = get_sign(str, &i);
    while (str[i] && str[i] == ' ')
        i += 1;
    while (str[i] && my_isnum(str[i])) {
        if (i > 0)
            nb *= 10;
        nb += str[i] - 48;
        i += 1;
    }
    return (nb * neg);
}