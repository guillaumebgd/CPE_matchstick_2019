/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** fills a line with the corresponding amount of matches
*/

#include <stdlib.h>
#include "matchstick.h"

static void setup_line(char **line, const int width)
{
    (*line)[0] = '*';
    (*line)[width + 1] = '*';
    (*line)[width + 2] = ' ';
    (*line)[width + 3] = '\0';
}

boolean_t fill_line(char **line, const int width, const int matches)
{
    int index_matches = 0;
    int index = 1;

    (*line) = malloc(sizeof(char) * (width + 4));
    if (!(*line))
        return (FALSE);
    setup_line(line, width);
    while (index <= (width - matches) / 2) {
        (*line)[index] = ' ';
        index += 1;
    }
    while (index_matches < matches) {
        (*line)[index] = '|';
        index += 1;
        index_matches += 1;
    }
    while (index < width + 1)
        (*line)[index++] = ' ';
    return (TRUE);
}