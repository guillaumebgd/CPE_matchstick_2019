/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** main file for matchstick project
*/

#include "matchstick.h"
#include "my.h"

int main(int ac, char **av)
{
    if (ac != 3) {
        usage();
        return (84);
    } else if (check_wrong_args(av[1], av[2]) == 1) {
        usage();
        return (84);
    }
    return (init_end_game(my_getnbr(av[1]), my_getnbr(av[2])));
}