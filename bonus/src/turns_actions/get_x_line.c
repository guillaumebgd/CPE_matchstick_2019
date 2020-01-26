/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** returns a pointer to a given line
*/

#include <stddef.h>
#include "matchstick.h"

lines_t *get_x_line(lines_t **head, const int line_nb)
{
    lines_t *tmp = NULL;

    if (!(*head))
        return (NULL);
    for (tmp = (*head); tmp->line_id != line_nb; tmp = tmp->next);
    return (tmp);
}