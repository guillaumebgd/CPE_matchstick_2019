/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** returns negative nb if first < second
*/

#include "my.h"

int my_strcmp(const char *first, const char *second)
{
    int len_first = my_strlen(first);
    int len_second = my_strlen(second);
    int index = 0;

    if (len_first == -1 || len_second == -1)
        return (len_first - len_second);
    if (len_first != len_second)
        return (len_first - len_second);
    while (first[index] && second[index]) {
        if (first[index] != second[index])
            break;
        index += 1;
    }
    return (first[index] - second[index]);
}
