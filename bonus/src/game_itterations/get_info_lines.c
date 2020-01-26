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

    stock = my_getnbr(written);
    if (stock == 0) {
        my_putstr(1, "Error: invalid input (positive number expected)\n");
        return (FALSE);
    }
    if (stock < 0 || stock > nb_lines) {
        my_putstr(1, "Error: this line is out of range\n");
        return (FALSE);
    }
    return (TRUE);
}

void get_info_lines(const info_t conditions, boolean_t *input,
                        const char *written)
{
    int index = 0;

    if (!written)
        return;
    while (written[index]) {
        if (!(my_isnum(written[index]))) {
            my_putstr(1, "Error: invalid input (positive number expected)\n");
            return;
        }
        index += 1;
    }
    if (!(check_valid_number(written, conditions.nb_lines)))
        return;
    (*input) = TRUE;
}