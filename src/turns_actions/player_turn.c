/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** actions done by the program when player if playing
*/

#include <stdlib.h>
#include "matchstick.h"
#include "my.h"

static boolean_t ask_input(input_t *player_input, const int mode)
{
    int len_written = 0;

    if (mode == 0)
        my_putstr(1, "Line: ");
    else
        my_putstr(1, "Matches: ");
    player_input->written = get_next_line(0, 4096);
    len_written = my_strlen(player_input->written);
    if (len_written < 0)
        return (FALSE);
    return (TRUE);
}

static boolean_t ask_for_turn(lines_t **head, input_t *player_input,
                                const info_t conditions)
{
    boolean_t input = FALSE;

    while (!input) {
        if (!(ask_input(player_input, 0)))
            return (FALSE);
        get_info_lines(player_input, conditions, &input);
        if (!input)
            continue;
        input = FALSE;
        player_input->asked_lines = my_getnbr(player_input->written);
        free(player_input->written);
        if (!(ask_input(player_input, 1)))
            return (FALSE);
        get_info_matches(head, conditions, player_input, &input);
        if (!input)
            continue;
        player_input->asked_matches = my_getnbr(player_input->written);
        free(player_input->written);
    }
    return (TRUE);
}

boolean_t player(lines_t **head, const info_t conditions)
{
    input_t player_input;

    player_input.written = NULL;
    player_input.asked_lines = 0;
    player_input.asked_matches = 0;
    my_putstr(1, "\nYour turn:\n");
    if (!(ask_for_turn(head, &player_input, conditions)))
        return (FALSE);
    rm_matches_from_line(head, conditions, player_input.asked_lines,
                        player_input.asked_matches);
    my_putstr(1, "Player removed ");
    my_put_nbr(player_input.asked_matches, "0123456789");
    my_putstr(1, " match(es) from line ");
    my_put_nbr(player_input.asked_lines, "0123456789");
    my_putchar('\n');
    return (TRUE);
}