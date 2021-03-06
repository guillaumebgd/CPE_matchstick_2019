/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** computes the ai's turn options
*/

#include <stdlib.h>
#include "matchstick.h"
#include "my.h"

static void get_ai_choice(lines_t **head, const info_t conditions,
                            ai_move_t *choice)
{
    if (!(*head))
        return;
    find_possible_lines(head, choice);
    if (!(choice->pos_lines))
        return;
    compute_move(head, conditions, choice);
    free(choice->pos_lines);
}

void ai(lines_t **head, const info_t conditions)
{
    ai_move_t choice;

    choice.pos_lines = NULL;
    choice.size = 0;
    choice.line = 1;
    choice.matches = 1;
    get_ai_choice(head, conditions, &choice);
    my_putstr(1, "\nAI's turn...\n");
    my_putstr(1, "AI removed ");
    my_put_nbr(choice.matches, "0123456789");
    my_putstr(1, " match(es) from line ");
    my_put_nbr(choice.line, "0123456789");
    my_putchar('\n');
}