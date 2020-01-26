/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** tests the fill_line function
*/

#include <criterion/criterion.h>
#include "matchstick.h"

Test(fill_line, simple_normal_test)
{
    char *line = NULL;
    int width = get_width(2);

    fill_line(&line, width, 3);
    cr_expect_str_eq(line, "*|||*\n");
    if (line)
        free(line);
}