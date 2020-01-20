/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** gets a random int between a min int and max int
*/

#include <stdlib.h>

int my_rand(int min, int max)
{
    return (rand() % (max - min) + min);
}