##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Lucas Duboisse
##

NAME	=	libmy_malloc.so

SRC	=	src/malloc.c		\
		src/expand.c		\
		src/utils.c			\
		src/search.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -shared -fpic -Iinclude/ -lm

all:		$(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC) $(CFLAGS)

test:
	gcc test/main.c src/*.c -Iinclude

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
