/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** computes random input
*/

#include "matchstick.h"
#include "my.h"

void random_input(lines_t **head, const info_t conditions, ai_move_t *choice)
{
    lines_t *tmp = (*head);

    choice->line = choice->pos_lines[my_rand(0, choice->size - 1)];
    tmp = get_x_line(head, choice->line);
    if (tmp->matches <= conditions.max_to_remove)
        choice->matches = my_rand(1, tmp->matches);
    else
        choice->matches = my_rand(1, conditions.max_to_remove);
}