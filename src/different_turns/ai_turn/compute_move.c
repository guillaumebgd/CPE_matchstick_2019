/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** computes the ai move
*/

#include "my.h"
#include "matchstick.h"

static void get_x_line(lines_t **tmp, const int line_nb)
{
    while ((*tmp)->line_id != line_nb)
        (*tmp) = (*tmp)->next;
}

static int rand_matches(const int max)
{
    if (max - 1 == 0)
        return (max);
    return (my_rand(1, max));
}

void compute_move(lines_t **head, const info_t conditions,
                    ai_move_t *choice)
{
    lines_t *tmp = (*head);

    if (!head)
        return;
    if (choice->size == 1)
        one_line_left(head, conditions, choice);
    else {
        choice->line = choice->pos_lines[my_rand(0, choice->size - 1)];
        get_x_line(&tmp, choice->line);
        if (tmp->matches <= conditions.max_to_remove)
            choice->matches = rand_matches(tmp->matches);
        else
            choice->matches = rand_matches(conditions.max_to_remove);
    }
    removes_matches_from_line(head, conditions, choice->line, choice->matches);
}