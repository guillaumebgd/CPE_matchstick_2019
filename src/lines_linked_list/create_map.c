/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** creates the matchstick map
*/

#include "matchstick.h"
#include <stdlib.h>

static void setup_line(char **line, const int width)
{
    (*line)[0] = '*';
    (*line)[width + 1] = '*';
    (*line)[width + 2] = '\n';
    (*line)[width + 3] = '\0';
}

static int fill_line(char **line, const int width, const int matches)
{
    int i = 1;
    int j = 0;

    (*line) = malloc(sizeof(char) * (width + 4));
    if (!(*line))
        return (1);
    setup_line(line, width);
    while (i <= (width - matches) / 2) {
        (*line)[i] = ' ';
        i += 1;
    }
    while (j < matches) {
        (*line)[i] = '|';
        i += 1;
        j += 1;
    }
    while (i < width + 1) {
        (*line)[i] = ' ';
        i += 1;
    }
}

static int add_node(lines_t **lines,
                    const int line_identifier,
                    const int width,
                    const int matches)
{
    lines_t *node = malloc(sizeof(lines_t));
    lines_t *tmp = (*lines);

    if (!node)
        return (1);
    while (tmp->next)
        tmp = tmp->next;
    node->line = NULL;
    if (fill_line(&node->line, width, matches) == 1)
        return (1);
    node->line_id = line_identifier;
    node->matches = matches;
    node->next = NULL;
    tmp->next = node;
    return (0);
}

static int add_first_node(lines_t **lines,
                            const int line_identifier,
                            const int width,
                            const int matches)
{
    lines_t *node = malloc(sizeof(lines_t));

    if (!node)
        return (1);
    node->line = NULL;
    if (fill_line(&node->line, width, matches) == 1)
        return (1);
    node->line_id = line_identifier;
    node->matches = matches;
    node->next = NULL;
    (*lines) = node;
    return (0);
}

int create_map(lines_t **lines, const int nb_lines, const int width)
{
    int i = 1;

    while (i <= nb_lines) {
        if (!(*lines))
            add_first_node(lines, i, width, i * 2 - 1);
        else
            add_node(lines, i, width, i * 2 - 1);
        i += 1;
    }
    return (0);
}