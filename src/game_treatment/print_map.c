/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** print_map.c
*/

#include "my.h"

void print_map(char **map, const unsigned int limit)
{
    unsigned int count = 0;

    while (count < limit) {
        my_putstr(map[count]);
        count += 1;
    }
}