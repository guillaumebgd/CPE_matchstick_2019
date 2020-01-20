/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** gets the size of a string and returns -1 if null
*/

int my_strlen(char const *str)
{
    int i = -1;

    if (str)
        while (str[++i]);
    return (i);
}