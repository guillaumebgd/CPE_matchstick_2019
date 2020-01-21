/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** checks if a given string contains two different numbers
*/

#include "matchstick.h"
#include "my.h"

boolean_t check_mul_nbr(const char *written)
{
    boolean_t check_nbr = FALSE;
    int index = 0;

    while (written[index] && written[index] == ' ')
        index += 1;
    while (written[index] && my_isnum(written[index])) {
        check_nbr = TRUE;
        index += 1;
    }
    while (written[index]) {
        if (written[index] != ' ')
            return (FALSE);
        index += 1;
    }
    return (check_nbr);
}