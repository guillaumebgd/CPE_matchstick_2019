/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** tests the random input function
*/

#include <criterion/criterion.h>
#include "matchstick.h"

static void init_basic_structs(info_t *conditions, ai_move_t *choice,
                                const int width)
{
    choice->line = 0;
    choice->matches = 0;
    choice->pos_lines = NULL;
    choice->size = 0;
    conditions->max_to_remove = 2;
    conditions->nb_lines = 3;
    conditions->width = width;
}

Test(random_input, simple_random_input_with_conditions)
{
    lines_t *head = NULL;
    info_t conditions;
    ai_move_t choice;
    int width = get_width(3);

    init_basic_structs(&conditions, &choice, width);
    create_map(&head, 3, width);
    rm_matches_from_line(&head, conditions, 1, 1);
    find_possible_lines(&head, &choice);
    random_input(&head, conditions, &choice);
    if (choice.line < 2 || choice.line > 3
        || choice.matches < 1 || choice.matches > 2)
        cr_assert_eq(1, 2);
    else
        cr_assert_eq(1, 1);
    free_lines(&head);
}