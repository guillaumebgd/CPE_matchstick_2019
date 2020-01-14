/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** checks for wrong arguments
*/

#include "my.h"

static unsigned int check_wrong_size(const int nb,
                                    const int smallest,
                                    const int max)
{
    if (nb <= smallest || nb >= max)
        return (1);
    return (0);
}

int check_wrong_args(char const *lines, char const *max_remove)
{
    int len_lines = my_strlen(lines);
    int lines_nb = my_getnbr(lines);
    int nb_max_remove = my_getnbr(max_remove);

    if (check_wrong_size(len_lines, 0, 3))
        return (1);
    if (lines_nb <= 1 || lines_nb >= 100 || nb_max_remove <= 0)
        return (1);
    return (0);
}