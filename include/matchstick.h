/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** header for matchstick project
*/

#ifndef MATCHSTICK_H_

#define MATCHSTICK_H_

enum TURN {
    PLAYER,
    AI
};

enum BOLEAN {
    TRUE,
    FALSE
};

typedef struct lines_s {
    char *line;
    int line_id;
    int matches;
    struct lines_s *next;
} lines_t;

typedef struct info_s {
    int nb_lines;
    int max_to_remove;
    int width;
} info_t;

typedef struct input_s {
    char *written;
    int asked_lines;
    int asked_matches;
} input_t;

void usage(void);
int check_wrong_args(char const *, char const *);

int init_end_game(const int, const int);
int get_width(const int);
int create_map(lines_t **, const int, const int);
void fill_basics_line(char **, const int);

enum TURN matchstick_game(lines_t **, const info_t);
int print_map(lines_t **, const char *);

void invalid_input(char **, int *, int *, const info_t);

void player(lines_t **, const info_t);
void get_info_lines(input_t *, const info_t, enum BOLEAN *);
void get_info_matches(lines_t **, input_t *, const info_t, enum BOLEAN *);

void ai(lines_t **, const info_t);
int find_possible_lines(lines_t **, int **);

void removes_matches_from_line(lines_t **, const info_t, const int, const int);

void free_lines(lines_t **);

#endif /* MATCHSTICK_H_ */