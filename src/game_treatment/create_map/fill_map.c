/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** fill_map.c
*/

#include "matchstick.h"

static void fill_top_bottom(char ***map,
                            const unsigned int width,
                            const unsigned int index)
{
    unsigned int count = 0;

    while (count < width) {
        (*map)[index][count] = '*';
        count += 1;
    }
}

static void fill_line_spaces(char ***map,
                            const unsigned int width,
                            const unsigned int index,
                            unsigned int *count)
{
    unsigned int save = 0;

    while (save < width / 2 - index) {
        (*map)[index][(*count)] = ' ';
        (*count) += 1;
        save += 1;
    }
}

static void fill_lines_matches(char ***map,
                                const unsigned int index,
                                unsigned int *count)
{
    unsigned int save = 0;

    while (save < index * 2 - 1) {
        (*map)[index][(*count)] = '|';
        (*count) += 1;
        save += 1;
    }
}

static void fill_lines_with_matches(char ***map,
                                    const unsigned int width,
                                    const unsigned int index)
{
    unsigned int count = 1;

    (*map)[index][0] = '*';
    (*map)[index][width - 1] = '*';
    fill_line_spaces(map, width, index, &count);
    fill_lines_matches(map, index, &count);
    fill_line_spaces(map, width, index, &count);
}

void fill_map(game_info_t *game)
{
    unsigned int count = 0;

    while (count < game->lines + 2) {
        if (count == 0 || count == game->lines + 1)
            fill_top_bottom(&game->map, game->width, count);
        else
            fill_lines_with_matches(&game->map, game->width, count);
        count += 1;
    }
}