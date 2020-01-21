/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** tests the create map function
*/

#include "matchstick.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>


static void create_first_bottom(char **first_bottom_lines,
                                const int width)
{
    int i = 0;

    (*first_bottom_lines) = malloc(sizeof(char) * (width + 4));
    (*first_bottom_lines)[width + 3] = '\0';
    (*first_bottom_lines)[width + 2] = '\n';
    while (i < width + 2) {
        (*first_bottom_lines)[i] = '*';
        i += 1;
    }
}

Test(create_map, simple_map_creation)
{
    lines_t *head = NULL;
    char *first_bottom_lines = NULL;
    int width = get_width(4);

    cr_redirect_stdout();
    create_map(&head, 4, width);
    create_first_bottom(&first_bottom_lines, width);
    print_map(&head, first_bottom_lines);
    cr_expect_stdout_eq_str("*********\n"
                            "*   |   *\n"
                            "*  |||  *\n"
                            "* ||||| *\n"
                            "*|||||||*\n"
                            "*********\n");
    free(first_bottom_lines);
    free_lines(&head);
}

Test(create_map, smallest_map)
{
    lines_t *head = NULL;
    char *first_bottom_lines = NULL;
    int width = get_width(2);

    cr_redirect_stdout();
    create_map(&head, 2, width);
    create_first_bottom(&first_bottom_lines, width);
    print_map(&head, first_bottom_lines);
    cr_expect_stdout_eq_str("*****\n"
                            "* | *\n"
                            "*|||*\n"
                            "*****\n");
    free(first_bottom_lines);
    free_lines(&head);
}

Test(create_map, big_map)
{
    lines_t *head = NULL;
    char *first_bottom_lines = NULL;
    int width = get_width(8);

    cr_redirect_stdout();
    create_map(&head, 8, width);
    create_first_bottom(&first_bottom_lines, width);
    print_map(&head, first_bottom_lines);
    cr_expect_stdout_eq_str("*****************\n"
                            "*       |       *\n"
                            "*      |||      *\n"
                            "*     |||||     *\n"
                            "*    |||||||    *\n"
                            "*   |||||||||   *\n"
                            "*  |||||||||||  *\n"
                            "* ||||||||||||| *\n"
                            "*|||||||||||||||*\n"
                            "*****************\n");
    free(first_bottom_lines);
    free_lines(&head);
}