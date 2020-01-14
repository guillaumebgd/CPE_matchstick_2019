/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** ai_turn.c
*/

#include "matchstick.h"
#include "my.h"
#include <stdlib.h>

static void get_ai_choice(lines_t **head, const info_t conditions,
                        int *chosen_line, int *chosen_matches)
{
    int *possible_lines = NULL;
    int size = 0;

    if (!(*head))
        return;
    size = find_possible_lines(head, &possible_lines);
    if (size == 0)
        return;
    free(possible_lines);
}

void ai(lines_t **head, const info_t conditions)
{
    int chosen_line = 0;
    int chosen_matches = 0;

    get_ai_choice(head, conditions, &chosen_line, &chosen_matches);
    my_putstr(1, "\nAI's turn...\n");
    my_putstr(1, "AI removed ");
    my_put_nbr(chosen_matches, "0123456789", 10);
    my_putstr(1, " match(es) from line ");
    my_put_nbr(chosen_line, "0123456789", 10);
    my_putchar('\n');
}