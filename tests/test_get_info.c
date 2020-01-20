/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** test_get_info.c
*/

#include "matchstick.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(get_info_lines, simple_lines_info)
{
    input_t player_input;
    info_t conditions;
    enum boolean input = FALSE;

    player_input.asked_lines = 0;
    player_input.asked_matches = 0;
    player_input.written = "10";
    conditions.max_to_remove = 4;
    conditions.nb_lines = 10;
    conditions.width = 19;
    get_info_lines(&player_input, conditions, &input);
    if (input == TRUE)
        cr_assert_eq(1, 1);
    else
        cr_assert_eq(1, 2);
}

Test(get_info_matches, simple_matches_info)
{
    input_t player_input;
    info_t conditions;
    enum boolean input = FALSE;

    player_input.asked_lines = 13;
    player_input.asked_matches = 0;
    player_input.written = "20";
    conditions.max_to_remove = 4;
    conditions.nb_lines = 13;
    conditions.width = 25;
    get_info_lines(&player_input, conditions, &input);
    if (input == FALSE)
        cr_assert_eq(1, 1);
    else
        cr_assert_eq(1, 2);
}