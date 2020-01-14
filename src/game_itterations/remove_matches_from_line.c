/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** finds the given live and removes matches from it
*/

#include "matchstick.h"

void removes_matches_from_line(lines_t **head,
                                const info_t conditions,
                                const int chosen_line,
                                const int to_remove)
{
    lines_t *tmp = (*head);
    int counter = 0;
    int i = 1;

    while (i < chosen_line) {
        i += 1;
        tmp = tmp->next;
    }
    i = conditions.width;
    while (tmp->line[i] == ' ')
        i -= 1;
    while (counter < to_remove) {
        tmp->line[i] = ' ';
        counter += 1;
        i -= 1;
    }
    tmp->matches -= to_remove;
}