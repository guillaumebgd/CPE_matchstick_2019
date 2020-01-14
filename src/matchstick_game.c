/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick_game.c
*/

#include "matchstick.h"
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

enum TURN matchstick_game(lines_t **head,
                        const info_t conditions)
{
    char *first_bottom_lines = NULL;
    enum TURN cur_turn = PLAYER;

    create_first_bottom(&first_bottom_lines, conditions.width);
    while ((check_if_finished(head) == FALSE)) {
        print_map(head, first_bottom_lines);
        cur_turn == PLAYER ? player(head, conditions) : ai(head, conditions);
        cur_turn = cur_turn == PLAYER ? AI : PLAYER;
    }
    print_map(head, first_bottom_lines);
    return (cur_turn);
}