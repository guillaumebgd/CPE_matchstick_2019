/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** checks for wrong arguments
*/

#include "matchstick.h"
#include "my.h"

static boolean_t check_wrong_size(const int nb, const int smallest,
                                    const int max)
{
    if (nb <= smallest || nb >= max)
        return (FALSE);
    return (TRUE);
}

boolean_t check_wrong_args(const char *lines, const char *max_remove)
{
    int len_lines = my_strlen(lines);
    int lines_nb = my_getnbr(lines);
    int nb_max_remove = my_getnbr(max_remove);

    if (check_wrong_size(len_lines, 0, 3))
        return (FALSE);
    if (lines_nb <= 1 || lines_nb >= 100 || nb_max_remove <= 0)
        return (FALSE);
    return (TRUE);
}