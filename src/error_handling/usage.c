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
            "     A small matchstick game played onto the terminal.\n"
            "\n"
            "     Indicate, after each turn, how many matches from\n"
            "     a line you want to remove (you can't remove more\n"
            "     matches than the line contains nor remove none).\n"
            "\n"
            "     n    number of lines the pyramid of matches has\n"
            "          n must be between this intervale: 1 < n < 100\n"
            "     max  maximum amount of matches that can be taken\n"
            "          out at once\n", 445);
}