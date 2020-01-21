/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** gets a random int between a min int and max int
*/

#include <stdlib.h>

int my_rand(const int min, const int max)
{
    if (!(max - min))
        return (max);
    return (rand() % (max - min) + min);
}