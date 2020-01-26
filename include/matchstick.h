/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** header for matchstick project
*/

#ifndef MATCHSTICK_H_

#define MATCHSTICK_H_

//helps keeping track of who is playing
typedef enum turn_e {
    PLAYER = 1,
    AI = 2,
} turn_t;

//a boolean enum, FALSE = 0, TRUE = 1
typedef enum boolean_e {
    FALSE,
    TRUE
} boolean_t;

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

typedef struct ai_move_s {
    int *pos_lines;
    int size;
    int line;
    int matches;
} ai_move_t;


//                          ******************
//                          | Error handling |
//                          ******************
//
//usage:            prints the usage of the matchstick program.
//check_wrong_args: checks if the given arguments are correct.
//                  -> Returns FALSE if there's an error,
//                  otherwise, returns TRUE.

void usage(void);
boolean_t check_wrong_args(const char *lines, const char *max_remove);


//      *************************************************************
//      | Initialize assets and frees assets of the matchstick game |
//      *************************************************************
//
//init_end_game: initializes the game and makes it end with the
//               right return value.
//get_width:     gets the width of a map based on its number of lines.

int init_end_game(const int nb_lines, const int max_rm);
int get_width(const int lines);


//
//                            ****************
//                            | Map handling |
//                            ****************
//
//create_map: creates the matchstick map in a linked list.
//fill_line:  symetricly fills a line.
//            -> Returns FALSE if there's an error, otherwise, returns TRUE.
//free_lines: frees resources from the lines_t linked list.

boolean_t create_map(lines_t **lines, const int nb_lines, const int width);
boolean_t fill_line(char **line, const int width, const int matches);
void free_lines(lines_t **head);


//                     *************************************
//                     | Main instances of the game output |
//                     *************************************
//
//matchstick_game: matchstick whole game.
//print_map:       prints the game state of the map.
//                 -> Returns FALSE if there's an error, otherwise,
//                 returns TRUE.
//print_winner:    prints the sentence the AI writes at the end of the game.
//                 -> Returns FALSE if there's an error, otherwise,
//                 returns TRUE.

int matchstick_game(lines_t **head, const info_t conditions);
boolean_t print_map(lines_t **head, const char *first_bottom_lines);
boolean_t print_winner(const turn_t winner);


//                       *****************
//                       | Player's turn |
//                       *****************
//
//player:           computes the player's turn actions
//                  -> Returns FALSE if there's an error, otherwise,
//                  returns TRUE.
//get_info_lines:   gets the line input from the player.
//get_info_matches: gets the matches input from the player.

boolean_t player(lines_t **head, const info_t conditions);
void get_info_lines(const info_t conditions, boolean_t *input,
                        const char *written);
void get_info_matches(lines_t **head, const info_t conditions,
                        input_t *player_input, boolean_t *input);


//                         *************
//                         | AI's turn |
//                         *************
//

void ai(lines_t **head, const info_t conditions);
void find_possible_lines(lines_t **head, ai_move_t *choice);
lines_t *get_x_line(lines_t **head, const int line_nb);
void compute_move(lines_t **head, const info_t conditions, ai_move_t *choice);

void one_line_left(lines_t **head, const info_t conditions, ai_move_t *choice);

void two_lines_left(lines_t **head, const info_t conditions,
                    ai_move_t *choice);
void one_at_one(lines_t **head, const int max_to_rm, ai_move_t *choice);

void random_input(lines_t **head, const info_t conditions, ai_move_t *choice);


//                      *******************
//                      | Assets on turns |
//                      *******************
//
//rm_matches_from_line: removes a chosen nb of matches on a chosen line.
//                      (Errors aren't checked here).

void rm_matches_from_line(lines_t **head, const info_t conditions,
                        const int chosen_line, const int to_remove);

#endif /* MATCHSTICK_H_ */