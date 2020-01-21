/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** gets the info given into input by the player
*/

#include <stdlib.h>
#include "matchstick.h"
#include "my.h"

static boolean_t check_valid_number(const char *written,
                                    const int nb_lines)
{
    int stock = 0;

    if (!(check_mul_nbr(written))) {
        my_putstr(1, "Error: invalid input (positive number expected)\n");
        return (FALSE);
    }
    stock = my_getnbr(written);
    if (stock <= 0 || stock > nb_lines) {
        my_putstr(1, "Error: this line is out of range\n");
        return (FALSE);
    }
    return (TRUE);
}

void get_info_lines(input_t *player_input, const info_t conditions,
                        boolean_t *input)
{
    int index = 0;

    if (!(player_input->written))
        return;
    while (player_input->written[index]) {
        if (!(my_isnum(player_input->written[index]))
            && player_input->written[index] != ' ') {
            my_putstr(1, "Error: invalid input (positive number expected)\n");
            return;
        }
        index += 1;
    }
    if (!(check_valid_number(player_input->written, conditions.nb_lines)))
        return;
    (*input) = TRUE;
}