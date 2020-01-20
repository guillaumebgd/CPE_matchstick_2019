/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** get_info_lines.c
*/

#include "matchstick.h"
#include "my.h"
#include <stdlib.h>

static enum boolean check_for_valid_removal(lines_t **head,
                                            input_t *player_input,
                                            int stock)
{
    lines_t *tmp = (*head);

    if (!tmp)
        return (FALSE);
    while (tmp->line_id < player_input->asked_lines)
        tmp = tmp->next;
    if (tmp->matches < stock)
        return (FALSE);
    return (TRUE);
}

static enum boolean check_conditions(lines_t **head, input_t *player_input,
                                    const int stock, const info_t conditions)
{
    if (stock == 0) {
        my_putstr(1, "Error: you have to remove at least one match\n");
        return (FALSE);
    }
    if (stock > conditions.max_to_remove) {
        my_putstr(1, "Error: you cannot remove more than ");
        my_put_nbr(conditions.max_to_remove, "0123456789", 10);
        my_putstr(1, " matches per turn\n");
        return (FALSE);
    }
    if (check_for_valid_removal(head, player_input, stock) == FALSE) {
        my_putstr(1, "Error: not enough matches on this line\n");
        return (FALSE);
    }
    return (TRUE);
}

static enum boolean check_valid_number(lines_t **head, input_t *player_input,
                                        const info_t conditions)
{
    int stock = 0;

    if (check_mul_nbr(player_input->written) == FALSE) {
        my_putstr(1, "Error: invalid input (positive number expected)\n");
        return (FALSE);
    }
    stock = my_getnbr(player_input->written);
    return (check_conditions(head, player_input, stock, conditions));
}

void get_info_matches(lines_t **head,
                    input_t *player_input,
                    const info_t conditions,
                    enum boolean *input)
{
    int i = 0;

    if (!(player_input->written))
        return;
    while (player_input->written[i]) {
        if ((player_input->written[i] < '0' || player_input->written[i] > '9')
            && player_input->written[i] != ' ') {
            my_putstr(1, "Error: invalid input (positive number expected)\n");
            return;
        }
        i += 1;
    }
    if (check_valid_number(head, player_input, conditions) == FALSE)
        return;
    (*input) = TRUE;
}