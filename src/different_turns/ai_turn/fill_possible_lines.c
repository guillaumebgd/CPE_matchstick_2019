/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** fills possible lines
*/

#include <stdlib.h>
#include "matchstick.h"

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
                        ai_move_t *choice)
{
    lines_t *tmp = NULL;

    tmp = (*head);
    while (tmp) {
        if (tmp->matches > 0)
            choice->size += 1;
        tmp = tmp->next;
    }
    if (choice->size == 0)
        return;
    choice->pos_lines = malloc(sizeof(int) * (choice->size + 1));
    if (!(choice->pos_lines))
        return;
    choice->pos_lines[choice->size] = -1;
    fill_possible_lines(head, &choice->pos_lines);
}