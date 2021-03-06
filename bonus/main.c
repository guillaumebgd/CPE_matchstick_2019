/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** main file of the matchstick project
*/

#include "matchstick.h"
#include "my.h"

int main(const int ac, const char * const *av)
{
    if (ac != 3) {
        usage();
        return (84);
    }
    if (!(check_wrong_args(av[1], av[2]))) {
        usage();
        return (84);
    }
    return (init_end_game(my_getnbr(av[1]), my_getnbr(av[2])));
}