/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** matchstick.h
*/

#ifndef MATCHSTICK_H_

#define MATCHSTICK_H_

typedef struct game_info_s {
    char **map;
    unsigned int lines;
    unsigned int width;
    unsigned int max_remove;
    unsigned int cur_line;
} game_info_t;

void usage(void);

unsigned int check_wrong_args(char const *, char const *);
unsigned int matchstick(const unsigned int, const unsigned int);
unsigned int allocate_map(char ***, const unsigned int, const unsigned int);
void fill_map(game_info_t *);

void print_map(char **, const unsigned int);

#endif /* MATCHSTICK_H_ */