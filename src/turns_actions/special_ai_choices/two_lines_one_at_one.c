/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** special case when 2 lines are left and at least one of them as only 1 match
*/

#include "matchstick.h"

static int one_and_one(ai_move_t *choice, const int matches_up,
                        const int matches_down)
{
    if (matches_up == 1 && matches_down == 1) {
        choice->line = choice->pos_lines[0];
        choice->matches = 1;
        return (0);
    }
    return (1);
}

static void remove_one_line(ai_move_t *choice, const int matches_up,
                            const int matches_down, const int max_to_rm)
{
    int line_several = matches_up == 1 ? 0 : 1;

    if (line_several == 0 && matches_down <= max_to_rm + 1) {
        choice->line = choice->pos_lines[1];
        choice->matches = matches_down;
    } else {
        choice->line = choice->pos_lines[0];
        choice->matches = matches_up;
    }
}

void one_at_one(lines_t **head, const int max_to_rm, ai_move_t *choice)
{
    int matches_up = get_x_line(head, choice->pos_lines[0])->matches;
    int matches_down = get_x_line(head, choice->pos_lines[1])->matches;
    int line_several = matches_up == 1 ? 0 : 1;

    if (one_and_one(choice, matches_up, matches_down) == 0)
        return;
    if ((line_several == 0 && matches_down <= max_to_rm + 1)
        || (line_several == 1 && matches_up <= max_to_rm + 1)) {
        remove_one_line(choice, matches_up, matches_down, max_to_rm);
        return;
    }
    if (line_several == 0)
        choice->line = choice->pos_lines[0];
    else
        choice->line = choice->pos_lines[1];
}