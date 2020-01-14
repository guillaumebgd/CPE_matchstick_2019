/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** gets the size of a string and returns -1 if null
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (-1);
    while (str[i])
        i += 1;
    return (i);
}