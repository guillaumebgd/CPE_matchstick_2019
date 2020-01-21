/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** frees memory used by the lines linked list
*/

#include <stdlib.h>
#include "matchstick.h"

void free_lines(lines_t **head)
{
    lines_t *tmp = NULL;

    for (tmp = (*head); tmp; tmp = (*head)) {
        (*head) = (*head)->next;
        free(tmp->line);
        free(tmp);
    }
}