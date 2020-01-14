/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** get_every_possible_lines.c
*/

#include "matchstick.h"
#include <stdlib.h>

static void fill_possible_lines(lines_t **head, int **possible_lines)
{
    lines_t *tmp = (*head);
    int index = 0;

    if (!tmp)
        return;
    tmp = (*head);
    while (tmp) {
        if (tmp->matches > 0) {
            (*possible_lines)[index] = tmp->line_id;
            index += 1;
        }
        tmp = tmp->next;
    }
}

void find_possible_lines(lines_t **head,
                        ai_move_t *ai_choice)
{
    lines_t *tmp = NULL;

    tmp = (*head);
    while (tmp) {
        if (tmp->matches > 0)
            ai_choice->choice_size += 1;
        tmp = tmp->next;
    }
    if (ai_choice->choice_size == 0)
        return;
    ai_choice->possible_lines = malloc(sizeof(int) * ai_choice->choice_size);
    if (!(ai_choice->possible_lines))
        return;
    fill_possible_lines(head, &ai_choice->possible_lines);
}