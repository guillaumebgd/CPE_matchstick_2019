/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** free_map.c
*/

#include <stdlib.h>

void free_map(char ***map, const unsigned int limit)
{
    unsigned int count = 0;

    while (count < limit) {
        if ((*map)[count] != NULL)
            free((*map)[count]);
        count += 1;
    }
    if ((*map) != NULL)
        free((*map));
}