/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** actions done by the program when player if playing
*/

#include "matchstick.h"
#include "my.h"
#include <stdlib.h>

static int ask_input(input_t *player_input, const int mode)
{
    int len_written = 0;

    if (mode == 0)
        my_putstr(1, "Line: ");
    else
        my_putstr(1, "Matches: ");
    player_input->written = get_next_line(0, 4096);
    len_written = my_strlen(player_input->written);
    if (len_written < 0)
        return (1);
    return (0);
}

static int ask_for_turn(lines_t **head,
                        input_t *player_input,
                        const info_t conditions)
{
    enum boolean input = FALSE;

    while (input == FALSE) {
        if (ask_input(player_input, 0) == 1)
            return (1);
        get_info_lines(player_input, conditions, &input);
        if (input == FALSE)
            continue;
        input = FALSE;
        player_input->asked_lines = my_getnbr(player_input->written);
        free(player_input->written);
        if (ask_input(player_input, 1) == 1)
            return (1);
        get_info_matches(head, player_input, conditions, &input);
        if (input == FALSE)
            continue;
        player_input->asked_matches = my_getnbr(player_input->written);
        free(player_input->written);
    }
    return (0);
}

int player(lines_t **head, const info_t conditions)
{
    input_t player_input;

    player_input.written = NULL;
    player_input.asked_lines = 0;
    player_input.asked_matches = 0;
    my_putstr(1, "\nYour turn:\n");
    if (ask_for_turn(head, &player_input, conditions) == 1)
        return (1);
    removes_matches_from_line(head, conditions, player_input.asked_lines,
                                player_input.asked_matches);
    my_putstr(1, "Player removed ");
    my_put_nbr(player_input.asked_matches, "0123456789", 10);
    my_putstr(1, " match(es) from line ");
    my_put_nbr(player_input.asked_lines, "0123456789", 10);
    my_putchar('\n');
    return (0);
}