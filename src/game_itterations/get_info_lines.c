/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** get_info_lines.c
*/

#include "matchstick.h"
#include "my.h"
#include <stdlib.h>

static enum BOLEAN check_valid_number(input_t *player_input,
                                    const info_t conditions)
{
    int stock = 0;

    stock = my_getnbr(player_input->written);
    if (stock <= 0 || stock > conditions.nb_lines) {
        my_putstr(1, "Error: this line is out of range\n");
        return (FALSE);
    }
    return (TRUE);
}

void get_info_lines(input_t *player_input,
                    const info_t conditions,
                    enum BOLEAN *input)
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
    if (check_valid_number(player_input, conditions) == FALSE)
        return;
    (*input) = TRUE;
}