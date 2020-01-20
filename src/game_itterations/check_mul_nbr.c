/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** check_mul_nbr.c
*/

#include "matchstick.h"

enum boolean check_mul_nbr(const char *written)
{
    enum boolean check_nbr = FALSE;
    int idx = 0;

    while (written[idx] && written[idx] == ' ')
        idx += 1;
    while (written[idx] && written[idx] >= '0' && written[idx] <= '9') {
        check_nbr = TRUE;
        idx += 1;
    }
    while (written[idx]) {
        if (written[idx] != ' ')
            return (FALSE);
        idx += 1;
    }
    return (check_nbr);
}