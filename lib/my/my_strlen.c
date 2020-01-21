/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** gets the size of a string and returns -1 if null
*/

int my_strlen(const char *str)
{
    int i = -1;

    if (str)
        while (str[++i]);
    return (i);
}