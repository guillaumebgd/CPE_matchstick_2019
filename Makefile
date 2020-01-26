##
## EPITECH PROJECT, 2020
## Makefile matchstick
## File description:
## compiles c files with libs into the matchstick game
##

SRC	=	src/error_handling/usage.c									\
		src/error_handling/check_wrong_args.c						\
		src/game_management/init_end_game.c							\
		src/game_management/matchstick_game.c						\
		src/game_management/get_width.c								\
		src/map_list/create_map.c									\
		src/map_list/setup_map.c									\
		src/map_list/free_lines.c									\
		src/game_itterations/get_info_lines.c						\
		src/game_itterations/get_info_matches.c						\
		src/game_itterations/print_info.c							\
		src/game_itterations/remove_matches_from_line.c				\
		src/turns_actions/player_turn.c								\
		src/turns_actions/ai_turn.c									\
		src/turns_actions/get_x_line.c								\
		src/turns_actions/fill_possible_lines.c						\
		src/turns_actions/compute_move.c							\
		src/turns_actions/special_ai_choices/one_line_left.c		\
		src/turns_actions/special_ai_choices/two_lines_left.c		\
		src/turns_actions/special_ai_choices/two_lines_one_at_one.c	\
		src/turns_actions/random_move.c

SRCTESTS	=	tests/test_create_map.c								\
				tests/test_get_info.c

MAIN	=	main.c

VPATH	=	/usr/local/lib/

NAME	=	matchstick

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include/

LDFLAGS	=	-L./lib/my

LDLIBS	=	-lmy

LDLIBTEST	=	-lmy -lcriterion

all:	$(NAME)

$(NAME):
	$(MAKE) -C ./lib/my
	$(CC) -o $@ $(MAIN) $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

debug:
	$(MAKE) -C ./lib/my
	$(CC) -g -o $@ $(SRC) $(MAIN) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

tests_run:
	$(MAKE) -C lib/my
	$(CC) -o $@ $(SRC) $(SRCTESTS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBTEST) --coverage
	./$@
	$(RM) $@

coverage:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

clean:
	$(RM) $(NAME)
	$(RM) debug
	$(RM) tests_run
	$(RM) *.gcda *.gcno
	$(RM) vgcore.*

fclean:	clean
	$(RM) lib/my/*.a
	$(RM) lib/my/*.o

re:	fclean all

.NOTPARALLEL:
.PHONY: all debug tests_run coverage clean fclean re