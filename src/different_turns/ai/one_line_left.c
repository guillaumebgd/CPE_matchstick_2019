/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** one_line_left.c
*/

#include "matchstick.h"
#include <stddef.h>

void one_line_left(lines_t **head, const info_t conditions,
                    ai_move_t *ai_choice)
{
    lines_t *tmp = (*head);

    ai_choice->chosen_line = ai_choice->possible_lines[0];
    while (tmp->line_id < ai_choice->possible_lines[0])
        tmp = tmp->next;
    if (tmp->matches == 1)
        ai_choice->chosen_matches = 1;
    else
        return;
}