/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** matchstick.c
*/

#include "matchstick.h"
#include <stddef.h>

static unsigned int get_width(const unsigned int lines)
{
    unsigned int width = 1;
    unsigned int count = 0;

    while (count < lines) {
        width += 2;
        count += 1;
    }
    return (width);
}

static unsigned int init_game(game_info_t *game,
                            const unsigned int lines,
                            const unsigned int max_remove)
{
    game->lines = lines;
    game->width = get_width(lines);
    game->max_remove = max_remove;
    game->cur_line = 0;
    game->map = NULL;
    allocate_map(&game->map, lines, game->width);
    if (game->map == NULL)
        return (84);
    fill_map(game);
    return (0);
}

unsigned int matchstick(const unsigned int lines,
                        const unsigned int max_remove)
{
    game_info_t game;

    init_game(&game, lines, max_remove);
    print_map(game.map, game.lines + 2);
    free_map(&game.map, game.lines + 2);
    return (0);
}