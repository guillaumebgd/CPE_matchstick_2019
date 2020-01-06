/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** check arguments
*/

#include "my.h"
#include "matchstick.h"

int main(int ac, char **av)
{
    if (ac != 3) {
        usage();
        return (84);
    }
    if (check_wrong_args(av[1], av[2]) == 1) {
        usage();
        return (84);
    }
    return (matchstick(my_getnbr(av[1]), my_getnbr(av[2])));
}