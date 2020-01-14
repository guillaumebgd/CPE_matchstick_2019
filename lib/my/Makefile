##
## EPITECH PROJECT, 2019
## Makefile lib
## File description:
## Makefile for lib
##

SRC	=	./my_getnbr.c		\
		./my_strlen.c		\
		./my_putstr.c		\
		./get_next_line.c	\
		./my_put_nbr.c		\
		./my_putchar.c

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

.NOTPARALLEL:
.PHONY: all clean fclean re