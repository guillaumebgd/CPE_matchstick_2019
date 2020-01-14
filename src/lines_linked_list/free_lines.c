/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** free_lines.c
*/

#include "matchstick.h"
#include <stdlib.h>

void free_lines(lines_t **head)
{
    lines_t *tmp = (*head);

    while (tmp) {
        (*head) = (*head)->next;
        free(tmp->line);
        free(tmp);
        tmp = (*head);
    }
}