/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** compute_move.c
*/

#include "matchstick.h"

void compute_move(lines_t **head, const info_t conditions,
                    ai_move_t *ai_choice)
{
    lines_t *tmp = (*head);

    if (!tmp)
        return;
    if (ai_choice->choice_size = 1)
        one_line_left(head, conditions, ai_choice);
    removes_matches_from_line(head, conditions, ai_choice->chosen_line,
                                ai_choice->chosen_matches);
}