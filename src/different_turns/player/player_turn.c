/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** actions done by the program when player if playing
*/

#include "matchstick.h"
#include "my.h"
#include <stdlib.h>

static void ask_for_turn(lines_t **head,
                        input_t *player_input,
                        const info_t conditions)
{
    enum BOLEAN input = FALSE;

    while (input == FALSE) {
        my_putstr(1, "Line: ");
        player_input->written = get_next_line(0, 4096);
        get_info_lines(player_input, conditions, &input);
    }
    input = FALSE;
    player_input->asked_lines = my_getnbr(player_input->written);
    free(player_input->written);
    my_putstr(1, "Matches: ");
    player_input->written = get_next_line(0, 4096);
    get_info_matches(head, player_input, conditions, &input);
    if (input == FALSE) {
        ask_for_turn(head, player_input, conditions);
        return;
    }
    player_input->asked_matches = my_getnbr(player_input->written);
    free(player_input->written);
}

void player(lines_t **head, const info_t conditions)
{
    input_t player_input;

    player_input.written = NULL;
    player_input.asked_lines = 0;
    player_input.asked_matches = 0;
    my_putstr(1, "\nYour turn:\n");
    ask_for_turn(head, &player_input, conditions);
    removes_matches_from_line(head, conditions, player_input.asked_lines,
                                player_input.asked_matches);
    my_putstr(1, "Player removed ");
    my_put_nbr(player_input.asked_matches, "0123456789", 10);
    my_putstr(1, " match(es) from line ");
    my_put_nbr(player_input.asked_lines, "0123456789", 10);
    my_putchar('\n');
}