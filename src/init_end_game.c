/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** init conditions and lines linked list then call the game
*/

#include "matchstick.h"
#include "my.h"
#include <stdlib.h>
#include <time.h>

static void init_conditions(info_t *conditions,
                            const int nb_lines,
                            const int max_rm)
{
    conditions->nb_lines = nb_lines;
    conditions->max_to_remove = max_rm;
    conditions->width = get_width(nb_lines);
}

int init_end_game(const int nb_lines, const int max_rm)
{
    lines_t *lines = NULL;
    info_t conditions;
    enum TURN winner = PLAYER;

    srand(time(0));
    init_conditions(&conditions, nb_lines, max_rm);
    if (create_map(&lines, nb_lines, conditions.width) == 1)
        return (84);
    winner = matchstick_game(&lines, conditions);
    free_lines(&lines);
    return (winner);
}