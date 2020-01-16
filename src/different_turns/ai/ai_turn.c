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
                        ai_move_t *ai_choice)
{
    if (!(*head))
        return;
    find_possible_lines(head, ai_choice);
    if (ai_choice->choice_size == 0)
        return;
    compute_move(head, conditions, ai_choice);
    free(ai_choice->pos_lines);
}

void ai(lines_t **head, const info_t conditions)
{
    ai_move_t ai_choice;

    ai_choice.pos_lines = NULL;
    ai_choice.choice_size = 0;
    ai_choice.chosen_line = 1;
    ai_choice.chosen_matches = 1;
    get_ai_choice(head, conditions, &ai_choice);
    my_putstr(1, "\nAI's turn...\n");
    my_putstr(1, "AI removed ");
    my_put_nbr(ai_choice.chosen_matches, "0123456789", 10);
    my_putstr(1, " match(es) from line ");
    my_put_nbr(ai_choice.chosen_line, "0123456789", 10);
    my_putchar('\n');
}