/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** get_all_possible_lines.c
*/

#include "matchstick.h"
#include <stdlib.h>

static void fill_possible_lines(lines_t **head, int **possible_lines)
{
    lines_t *tmp = NULL;
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

int find_possible_lines(lines_t **head,
                        int **possible_lines)
{
    lines_t *tmp = NULL;
    int size = 0;

    tmp = (*head);
    while (tmp) {
        if (tmp->matches > 0)
            size += 1;
        tmp = tmp->next;
    }
    if (size == 0)
        return (0);
    (*possible_lines) = malloc(sizeof(int) * size);
    if (!(*possible_lines))
        return (0);
    fill_possible_lines(head, possible_lines);
    return (size);
}