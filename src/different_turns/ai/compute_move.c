/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** compute_move.c
*/

#include "matchstick.h"

static void get_x_line(lines_t **tmp, int line_nb)
{
    while ((*tmp)->line_id != line_nb)
        (*tmp) = (*tmp)->next;
}

static int find_line(ai_move_t *ai_choice)
{
    int n = 0;

    n = ai_choice->pos_lines[get_random_int_between(1, ai_choice->choice_size)];
    return (n);
}

void compute_move(lines_t **head, const info_t conditions,
                    ai_move_t *ai_choice)
{
    lines_t *tmp = (*head);

    if (!head)
        return;
    if (ai_choice->choice_size == 1)
        one_line_left(head, conditions, ai_choice);
    else {
        ai_choice->chosen_line = find_line(ai_choice);
        get_x_line(&tmp, ai_choice->chosen_line);
        ai_choice->chosen_matches = get_random_int_between(1, tmp->matches + 1);
    }
    removes_matches_from_line(head, conditions,
                    ai_choice->chosen_line, ai_choice->chosen_matches);
}