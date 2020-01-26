/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** algorithm exploited by the ai when two lines are left in the game
*/

#include "matchstick.h"

void two_lines_left(lines_t **head, const info_t conditions, ai_move_t *choice)
{
    int matches_up = get_x_line(head, choice->pos_lines[0])->matches;
    int matches_down = get_x_line(head, choice->pos_lines[1])->matches;

    if (matches_up == 1 || matches_down == 1)
        one_at_one(head, conditions.max_to_remove, choice);
    else
        random_input(head, conditions, choice);
}