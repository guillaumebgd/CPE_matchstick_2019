/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** gets the nb of matches a player wants to remove
*/

#include <stdlib.h>
#include "matchstick.h"
#include "my.h"

static boolean_t check_for_valid_removal(lines_t **head, const int asked_line,
                                        const int stock)
{
    lines_t *tmp = NULL;

    if (!(*head))
        return (FALSE);
    for (tmp = (*head); tmp->line_id < asked_line; tmp = tmp->next);
    if (tmp->matches < stock)
        return (FALSE);
    return (TRUE);
}

static boolean_t check_conditions(lines_t **head, input_t *player_input,
                                const int stock, const int max_rm)
{
    if (!(stock)) {
        my_putstr(1, "Error: you have to remove at least one match\n");
        return (FALSE);
    }
    if (stock > max_rm) {
        my_putstr(1, "Error: you cannot remove more than ");
        my_put_nbr(max_rm, "0123456789");
        my_putstr(1, " matches per turn\n");
        return (FALSE);
    }
    if (!(check_for_valid_removal(head, player_input->asked_lines, stock))) {
        my_putstr(1, "Error: not enough matches on this line\n");
        return (FALSE);
    }
    return (TRUE);
}

static boolean_t check_valid_number(lines_t **head, input_t *player_input,
                                    const int max_rm)
{
    int stock = 0;

    if (!(check_mul_nbr(player_input->written))) {
        my_putstr(1, "Error: invalid input (positive number expected)\n");
        return (FALSE);
    }
    stock = my_getnbr(player_input->written);
    return (check_conditions(head, player_input, stock, max_rm));
}

void get_info_matches(lines_t **head, const info_t conditions,
                        input_t *player_input, boolean_t *input)
{
    int index = 0;

    if (!(player_input->written))
        return;
    if (my_strcmp("2147483647", player_input->written) < 0) {
        my_putstr(1, "Error: not enough matches on this line\n");
        return;
    }
    while (player_input->written[index]) {
        if (!(my_isnum(player_input->written[index]))
            && player_input->written[index] != ' ') {
            my_putstr(1, "Error: invalid input (positive number expected)\n");
            return;
        }
        index += 1;
    }
    if (!(check_valid_number(head, player_input, conditions.max_to_remove)))
        return;
    (*input) = TRUE;
}