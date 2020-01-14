/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** fill_basics_line.c
*/

void fill_basics_line(char **line, const int width)
{
    (*line)[width + 3] = '\0';
    (*line)[width + 2] = '\n';
    (*line)[width + 1] = '*';
    (*line)[0] = '*';
}