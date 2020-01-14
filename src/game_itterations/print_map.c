/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** prints the matchstick map onto the terminal
*/

#include "matchstick.h"
#include "my.h"

int print_map(lines_t **head, const char *first_bottom_lines)
{
    lines_t *tmp = (*head);

    my_putstr(1, first_bottom_lines);
    while (tmp) {
        my_putstr(1, tmp->line);
        tmp = tmp->next;
    }
    my_putstr(1, first_bottom_lines);
}