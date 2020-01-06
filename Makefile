##
## EPITECH PROJECT, 2019
## Makefile matchstick
## File description:
## compiles c files into a lib
##

SRC		=	./src/error_handling/usage.c					\
			./src/error_handling/check_wrong_args.c			\
			./src/game_treatment/matchstick.c				\
			./src/game_treatment/print_map.c				\
			./src/game_treatment/free_map.c					\
			./src/game_treatment/create_map/allocate_map.c	\
			./src/game_treatment/create_map/fill_map.c		\

MAIN	=	./src/main.c

CFLAGS	=	-Wall -Wextra -I./include/

NAME	=	matchstick

LIB		=	-L./lib/my/ -lmy

CRIT	=	--coverage -lcriterion

all:	$(NAME)

$(NAME):
	$(MAKE) -C ./lib/my
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(LIB) $(CFLAGS)

tests_run:
	$(MAKE) -C ./lib/my
	$(RM) *.gcda *.gcno
	$(CC) -o unit_tests $(SRC) tests/*.c $(LIB) $(CRIT) $(CFLAGS)
	./unit_tests
	$(RM) unit_tests
	$(RM) test_*

coverage:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

valgrind:
	$(MAKE) -C ./lib/my
	$(CC) -o val $(MAIN) $(SRC) $(LIB) $(CFLAGS) -g
	valgrind ./val 10 1
	$(RM) val

debug:
	$(MAKE) -C ./lib/my
	$(CC) -o debug $(MAIN) $(SRC) $(LIB) $(CFLAGS) -g
	gdb ./debug
	$(RM) debug

clean:
	$(RM) $(OBJ)
	$(RM) *.gcna *.gcno
	$(RM) vgcore.*
	$(RM) unit_tests
	$(RM) val
	$(RM) debug

fclean:	clean
	$(RM) $(NAME)
	$(RM) ./lib/my/*.o
	$(RM) ./lib/my/*.a

re:	fclean all

.PHONY: all tests_run coverage valgrind debug clean fclean re
