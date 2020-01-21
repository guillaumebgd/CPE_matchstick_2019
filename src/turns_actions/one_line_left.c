/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** algorithm when one line is left in the game
*/

#include "matchstick.h"
#include <stddef.h>

static void find_best_pick(const int nb_matches, ai_move_t *choice,
                            const int max_to_rm)
{
    if (nb_matches <= max_to_rm + 1) {
        choice->matches = nb_matches - 1;
        return;
    }
    if ((nb_matches - 1) % (max_to_rm + 1) != 0) {
        choice->matches = (nb_matches - 1) % (max_to_rm + 1);
        return;
    }
    if (nb_matches > max_to_rm + 1 && nb_matches <= max_to_rm * 2 + 1)
        choice->matches = nb_matches - max_to_rm - 1;
}

void one_line_left(lines_t **head, const info_t conditions, ai_move_t *choice)
{
    lines_t *tmp = (*head);

    choice->line = choice->pos_lines[0];
    while (tmp->line_id < choice->pos_lines[0])
        tmp = tmp->next;
    if (tmp->matches == 1)
        choice->matches = 1;
    else
        find_best_pick(tmp->matches, choice, conditions.max_to_remove);
}