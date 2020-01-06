/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** check arguments
*/

#include "matchstick.h"

int main(int ac, char **av)
{
    if (ac != 3) {
        usage();
        return (84);
    }
    return (0);
}