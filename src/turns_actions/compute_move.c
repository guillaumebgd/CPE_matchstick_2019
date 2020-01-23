/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** computes the ai move
*/

#include "my.h"
#include "matchstick.h"

void compute_move(lines_t **head, const info_t conditions, ai_move_t *choice)
{
    if (!head)
        return;
    if (choice->size == 1)
        one_line_left(head, conditions, choice);
    else
        random_input(head, conditions, choice);
    rm_matches_from_line(head, conditions, choice->line, choice->matches);
}