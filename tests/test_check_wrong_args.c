/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** tests if the given arguments are correct
*/

#include <criterion/criterion.h>
#include "matchstick.h"

Test(check_wrong_args, correct_arguments)
{
    if (check_wrong_args("2", "3") == TRUE)
        cr_assert_eq(1, 1);
    else
        cr_assert_eq(1, 2);
}

Test(check_wrong_args, wrong_args_alpha)
{
    if (check_wrong_args("ab", "3") == FALSE)
        cr_assert_eq(1, 1);
    else
        cr_assert_eq(1, 2);
}

Test(check_wrong_args, zero_lines)
{
    if (check_wrong_args("0", "3") == FALSE)
        cr_assert_eq(1, 1);
    else
        cr_assert_eq(1, 2);
}

Test(check_wrong_args, overflow_checker)
{
    if (check_wrong_args("99", "2147483647") == TRUE)
        cr_assert_eq(1, 1);
    else
        cr_assert_eq(1, 2);
}