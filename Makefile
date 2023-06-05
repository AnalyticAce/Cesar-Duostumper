##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	cesar.c

OBJ	=	$(SRC:.c=.o)

NAME	=	cesar

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ);
	rm *~
	rm *#
	rm *.o

fclean:	clean
	rm -f	$(NAME)

re:	fclean all

.PHONY:		re clean fclean all
