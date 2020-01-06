/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** prints the usage of the push_swap program
*/

#include <unistd.h>

void usage(void)
{
    write(1, "USAGE\n"
            "     ./matchstick n max\n"
            "DESCRITION\n"
            "     n    number of lines the pyramid of matches has\n"
            "     max  maximum amount of matches that can be taken\n"
            "          out at once\n", 170);
}