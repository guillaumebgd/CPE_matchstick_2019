/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** allocate_map.c
*/

#include <stdlib.h>

unsigned int allocate_map(char ***map, const unsigned int lines,
                        const unsigned int width)
{
    unsigned int count = 0;

    (*map) = malloc(sizeof(char *) * lines + 2);
    if ((*map) == NULL)
        return (84);
    while (count < lines + 2) {
        (*map)[count] = malloc(sizeof(char) * width + 2);
        if ((*map)[count] == NULL)
            return (84);
        (*map)[count][width] = '\n';
        (*map)[count][width + 1] = '\0';
        count += 1;
    }
    return (0);
}