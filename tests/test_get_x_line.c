/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** tests the get_x_line function
*/

#include <criterion/criterion.h>
#include "matchstick.h"

Test(get_x_line, simple_line_query)
{
    lines_t *head = NULL;
    lines_t *tmp = NULL;
    int width = get_width(4);

    create_map(&head, 4, width);
    tmp = get_x_line(&head, 3);
    if (tmp->line_id == 3)
        cr_assert_eq(1, 1);
    else
        cr_assert_eq(1, 2);
    free_lines(&head);
}

Test(get_x_line, head_is_null)
{
    lines_t *head = NULL;
    lines_t *tmp = NULL;
    int width = get_width(4);

    tmp = get_x_line(&head, 3);
    if (tmp)
        cr_assert_eq(1, 2);
    else
        cr_assert_eq(1, 1);
    free_lines(&head);
}