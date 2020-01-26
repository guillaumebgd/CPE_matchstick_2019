/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** main control over the matchstick game
*/

#include <stdlib.h>
#include "matchstick.h"
#include "my.h"

static boolean_t create_first_bottom(char **first_bottom_lines,
                                    const int width)
{
    int i = 0;

    (*first_bottom_lines) = malloc(sizeof(char) * (width + 4));
    if (!(*first_bottom_lines))
        return (FALSE);
    (*first_bottom_lines)[width + 3] = '\0';
    (*first_bottom_lines)[width + 2] = '\n';
    for (i = 0; i < width + 2; i += 1)
        (*first_bottom_lines)[i] = '*';
    return (TRUE);
}

static boolean_t check_if_finished(lines_t **head)
{
    lines_t *tmp = NULL;

    for (tmp = (*head); tmp; tmp = tmp->next) {
        if (tmp->matches > 0)
            return (FALSE);
    }
    return (TRUE);
}

static boolean_t action_turn(const turn_t cur_turn, lines_t **head,
                            const info_t conditions)
{
    if (cur_turn == PLAYER) {
        if (!(player(head, conditions)))
            return (FALSE);
    } else
        ai(head, conditions);
    return (TRUE);
}

int matchstick_game(lines_t **head, const info_t conditions)
{
    char *first_bottom_lines = NULL;
    turn_t cur_turn = PLAYER;

    if (!(create_first_bottom(&first_bottom_lines, conditions.width)))
        return (84);
    while (!(check_if_finished(head))) {
        if (!(print_map(head, first_bottom_lines)))
            return (84);
        if (!(action_turn(cur_turn, head, conditions)))
            return (0);
        cur_turn = cur_turn == PLAYER ? AI : PLAYER;
    }
    if (!(print_map(head, first_bottom_lines)))
        return (84);
    if (!(print_winner(cur_turn)))
        return (84);
    return (cur_turn);
}