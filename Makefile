##
## EPITECH PROJECT, 2019
## Makefile matchstick
## File description:
## compiles c files into a lib
##

SRC		=	./src/error_handling/usage.c	\

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

debug:
	$(MAKE) -C ./lib/my
	$(CC) -o debug $(MAIN) $(SRC) $(LIB) $(CFLAGS) -g
	gdb ./debug
	$(RM) debug

clean:
	$(RM) $(OBJ)
	$(RM) *.gc*
	$(RM) unit_tests

fclean:	clean
	$(RM) $(NAME)
	$(RM) ./lib/my/*.o
	$(RM) ./lib/my/*.a

re:	fclean all

.PHONY: all tests_run coverage debug clean fclean re
