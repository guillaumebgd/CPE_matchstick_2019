##
## EPITECH PROJECT, 2019
## Makefile matchstick
## File description:
## compiles c files with libs into matchstick game
##

SRC	=	src/error_handlers/usage.c							\
		src/error_handlers/check_wrong_args.c				\
		src/init_end_game.c									\
		src/matchstick_game.c								\
		src/get_width.c										\
		src/lines_linked_list/create_map.c					\
		src/lines_linked_list/fill_basics_line.c			\
		src/lines_linked_list/free_lines.c					\
		src/game_itterations/check_mul_nbr.c				\
		src/game_itterations/get_info_lines.c				\
		src/game_itterations/get_info_matches.c				\
		src/game_itterations/print_map.c					\
		src/game_itterations/remove_matches_from_line.c		\
		src/different_turns/player/player_turn.c			\
		src/different_turns/ai/ai_turn.c					\
		src/different_turns/ai/get_every_possible_lines.c	\
		src/different_turns/ai/compute_move.c				\
		src/different_turns/ai/one_line_left.c

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
	$(CC) -o $@ $(SRC) tests/*.c $(CPPFLAGS) $(LDFLAGS) $(LDLIBTEST) --coverage
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