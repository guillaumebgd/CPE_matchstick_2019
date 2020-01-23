/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** tests the get_info functions
*/

#include "matchstick.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(get_info_lines, simple_lines_info)
{
    input_t player_input;
    info_t conditions;
    boolean_t input = FALSE;

    player_input.asked_lines = 0;
    player_input.asked_matches = 0;
    player_input.written = "10";
    conditions.max_to_remove = 4;
    conditions.nb_lines = 10;
    conditions.width = 19;
    get_info_lines(conditions, &input, player_input.written);
    if (input)
        cr_assert_eq(1, 1);
    else
        cr_assert_eq(1, 2);
}

Test(get_info_matches, simple_matches_info)
{
    input_t player_input;
    info_t conditions;
    boolean_t input = FALSE;

    player_input.asked_lines = 13;
    player_input.asked_matches = 0;
    player_input.written = "20";
    conditions.max_to_remove = 4;
    conditions.nb_lines = 13;
    conditions.width = 25;
    get_info_lines(conditions, &input, player_input.written);
    if (!input)
        cr_assert_eq(1, 1);
    else
        cr_assert_eq(1, 2);
}