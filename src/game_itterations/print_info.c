/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** prints the matchstick map onto the terminal
*/

#include <stddef.h>
#include "matchstick.h"
#include "my.h"

boolean_t print_winner(const turn_t winner)
{
    if (winner == PLAYER) {
        if (my_putstr(1, "I lost... snif... but I'll get you next time!!\n"))
            return (FALSE);
    } else {
        if (my_putstr(1, "You lost, too bad...\n"))
            return (FALSE);
    }
    return (TRUE);
}

boolean_t print_map(lines_t **head, const char *first_bottom_lines)
{
    lines_t *tmp = NULL;

    if (my_putstr(1, first_bottom_lines))
        return (FALSE);
    for (tmp = (*head); tmp; tmp = tmp->next) {
        if (my_putstr(1, tmp->line))
            return (FALSE);
    }
    if (my_putstr(1, first_bottom_lines))
        return (FALSE);
    return (TRUE);
}