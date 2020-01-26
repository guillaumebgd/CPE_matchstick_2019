/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** creates the matchstick map
*/

#include <stdlib.h>
#include "matchstick.h"

static boolean_t add_node(lines_t **lines, const int line_identifier,
                            const int width, const int matches)
{
    lines_t *node = malloc(sizeof(lines_t));
    lines_t *tmp = NULL;

    if (!node)
        return (FALSE);
    for (tmp = (*lines); tmp->next; tmp = tmp->next);
    node->line = NULL;
    if (!(fill_line(&node->line, width, matches)))
        return (FALSE);
    node->line_id = line_identifier;
    node->matches = matches;
    node->next = NULL;
    tmp->next = node;
    return (TRUE);
}

static boolean_t add_first_node(lines_t **lines, const int line_identifier,
                                const int width, const int matches)
{
    lines_t *node = malloc(sizeof(lines_t));

    if (!node)
        return (FALSE);
    node->line = NULL;
    if (!(fill_line(&node->line, width, matches)))
        return (FALSE);
    node->line_id = line_identifier;
    node->matches = matches;
    node->next = NULL;
    (*lines) = node;
    return (TRUE);
}

static boolean_t add_new_node(lines_t **lines, const int index,
                                const int width)
{
    if (!(*lines)) {
        if (!(add_first_node(lines, index, width, index * 2 - 1)))
            return (FALSE);
    } else {
        if (!(add_node(lines, index, width, index * 2 - 1)))
            return (FALSE);
    }
    return (TRUE);
}

boolean_t create_map(lines_t **lines, const int nb_lines, const int width)
{
    int index = 1;

    while (index <= nb_lines) {
        if (!(add_new_node(lines, index, width)))
            return (FALSE);
        index += 1;
    }
    return (TRUE);
}