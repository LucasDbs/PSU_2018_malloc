##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Lucas Duboisse
##

NAME	=	libmy_malloc.so

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -W -Wall -Wextra -O -shared -fpic

all:		$(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
