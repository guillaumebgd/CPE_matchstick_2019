/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** tests the compute_move functions
*/

#include <criterion/criterion.h>
#include "matchstick.h"

Test(compute_move, one_matchstick_left)
{
    lines_t *head = NULL;
    info_t conditions;
    ai_move_t choice;
    int width = get_width(2);

    choice.line = 0;
    choice.matches = 0;
    choice.pos_lines = (int[]){1, -1};
    choice.size = 1;
    conditions.max_to_remove = 3;
    conditions.nb_lines = 2;
    conditions.width = width;
    create_map(&head, 2, width);
    rm_matches_from_line(&head, conditions, 2, 3);
    compute_move(&head, conditions, &choice);
    if (choice.line != 1 && choice.matches != 1)
        cr_assert_eq(1, 2);
    else
        cr_assert_eq(1, 1);
}