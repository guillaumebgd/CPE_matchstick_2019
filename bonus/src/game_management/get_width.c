/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** gets the width of a matchstick map
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