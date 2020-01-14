/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** get_width.c
*/

int get_width(const int lines)
{
    int width = 1;
    int count = 0;

    while (count < lines - 1) {
        width += 2;
        count += 1;
    }
    return (width);
}