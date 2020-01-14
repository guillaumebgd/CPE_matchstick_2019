/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick_game.c
*/

#include "matchstick.h"
#include "my.h"
#include <stdlib.h>

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

static enum BOLEAN check_if_finished(lines_t **head)
{
    lines_t *tmp = (*head);

    while (tmp) {
        if (tmp->matches > 0)
            return (FALSE);
        tmp = tmp->next;
    }
    return (TRUE);
}

static int action_turn(enum TURN cur_turn, lines_t **head,
                        const info_t conditions)
{
    if (cur_turn == PLAYER) {
        if (player(head, conditions) == 1)
            return (1);
    } else
        ai(head, conditions);
    return (0);
}

static void print_winner(enum TURN winner)
{
    if (winner == PLAYER)
        my_putstr(1, "I lost... snif... but I'll get you next time!!\n");
    else
        my_putstr(1, "You lost, too bad...\n");
}

enum TURN matchstick_game(lines_t **head,
                        const info_t conditions)
{
    char *first_bottom_lines = NULL;
    enum TURN cur_turn = PLAYER;

    create_first_bottom(&first_bottom_lines, conditions.width);
    while ((check_if_finished(head) == FALSE)) {
        print_map(head, first_bottom_lines);
        if (action_turn(cur_turn, head, conditions) == 1)
            return (cur_turn);
        cur_turn = cur_turn == PLAYER ? AI : PLAYER;
    }
    print_map(head, first_bottom_lines);
    print_winner(cur_turn);
    return (cur_turn);
}