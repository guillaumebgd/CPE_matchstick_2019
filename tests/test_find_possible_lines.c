/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** tests the find_possible_lines function
*/

#include <criterion/criterion.h>
#include "matchstick.h"

Test(find_possible_lines, simple_find)
{
    lines_t *head = NULL;
    info_t conditions;
    ai_move_t choice;
    int width = get_width(4);

    conditions.max_to_remove = 5;
    conditions.nb_lines = 4;
    conditions.width = width;
    choice.size = 0;
    create_map(&head, 4, width);
    rm_matches_from_line(&head, conditions, 1, 1);
    rm_matches_from_line(&head, conditions, 3, 5);
    find_possible_lines(&head, &choice);
    if (!choice.pos_lines || !choice.pos_lines[0] || !choice.pos_lines[1])
        cr_assert_eq(1, 2);
    else {
        cr_assert_eq(choice.pos_lines[0], 2);
        cr_assert_eq(choice.pos_lines[1], 4);
        cr_assert_eq(choice.pos_lines[2], -1);
    }
}

Test(find_possible_lines, nothing_left)
{
    lines_t *head = NULL;
    info_t conditions;
    ai_move_t choice;
    int width = get_width(2);

    conditions.max_to_remove = 5;
    conditions.nb_lines = 2;
    conditions.width = width;
    choice.pos_lines = NULL;
    choice.size = 0;
    create_map(&head, 2, width);
    rm_matches_from_line(&head, conditions, 1, 1);
    rm_matches_from_line(&head, conditions, 2, 3);
    find_possible_lines(&head, &choice);
    if (!(choice.pos_lines))
        cr_assert_eq(1, 1);
    else
        cr_assert_eq(1, 2);
}