/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** returns 0 if a char is a number, else, returns 1
*/

int my_isnum(const char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}