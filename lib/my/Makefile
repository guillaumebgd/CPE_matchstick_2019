##
## EPITECH PROJECT, 2019
## Makefile lib
## File description:
## makefile for lib
##

SRC	=	./my_getnbr.c

CFLAGS	=	-Wall -Wextra -I./../../include/

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) *.o

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
