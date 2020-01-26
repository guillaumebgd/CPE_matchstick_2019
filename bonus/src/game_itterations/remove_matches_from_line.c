/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** finds the given line and removes matches from it
*/

#include <stddef.h>
#include "matchstick.h"

void rm_matches_from_line(lines_t **head, const info_t conditions,
                        const int chosen_line, const int to_remove)
{
    lines_t *tmp = NULL;
    int counter = 0;
    int index = 1;

    for (tmp = (*head); index < chosen_line; tmp = tmp->next)
        index += 1;
    for (index = conditions.width; tmp->line[index] == ' '; index -= 1);
    while (counter < to_remove) {
        tmp->line[index] = ' ';
        counter += 1;
        index -= 1;
    }
    tmp->matches -= to_remove;
}