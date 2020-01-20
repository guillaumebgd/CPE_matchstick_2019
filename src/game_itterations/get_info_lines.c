/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** get_info_lines.c
*/

#include "matchstick.h"
#include "my.h"
#include <stdlib.h>

static enum boolean check_valid_number(const char *written,
                                    const info_t conditions)
{
    int stock = 0;

    if (check_mul_nbr(written) == FALSE) {
        my_putstr(1, "Error: invalid input (positive number expected)\n");
        return (FALSE);
    }
    stock = my_getnbr(written);
    if (stock <= 0 || stock > conditions.nb_lines) {
        my_putstr(1, "Error: this line is out of range\n");
        return (FALSE);
    }
    return (TRUE);
}

void get_info_lines(input_t *player_input,
                    const info_t conditions,
                    enum boolean *input)
{
    int index = 0;

    if (!(player_input->written))
        return;
    while (player_input->written[index]) {
        if ((player_input->written[index] < '0'
            || player_input->written[index] > '9')
            && player_input->written[index] != ' ') {
            my_putstr(1, "Error: invalid input (positive number expected)\n");
            return;
        }
        index += 1;
    }
    if (check_valid_number(player_input->written, conditions) == FALSE)
        return;
    (*input) = TRUE;
}