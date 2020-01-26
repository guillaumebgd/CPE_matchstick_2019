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

static void print_leftovers(lines_t *tmp)
{
    my_putstr(1, "\e[93;49m");
    my_putstr(1, "Line: ");
    my_putstr(1, "\x1b[0m");
    my_put_nbr(tmp->line_id, "0123456789");
    my_putstr(1, ", ");
    if (tmp->matches > 0)
        my_putstr(1, "\e[95;49m");
    else
        my_putstr(1, "\e[91;49m");
    my_putstr(1, "Matches left: ");
    my_putstr(1, "\x1b[0m");
    my_put_nbr(tmp->matches, "0123456789");
    my_putstr(1, "\n");
    my_putstr(1, "\x1b[0m");
}

boolean_t print_map(lines_t **head, const char *first_bottom_lines)
{
    lines_t *tmp = NULL;

    if (!(*head))
        return (FALSE);
    my_putstr(1, "\e[94;49m");
    my_putstr(1, first_bottom_lines);
    for (tmp = (*head); tmp; tmp = tmp->next) {
        my_putstr(1, "\e[94;49m");
        my_putstr(1, tmp->line);
        print_leftovers(tmp);
    }
    my_putstr(1, "\e[94;49m");
    my_putstr(1, first_bottom_lines);
    my_putstr(1, "\x1b[0m");
    return (TRUE);
}