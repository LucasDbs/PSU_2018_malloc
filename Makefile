##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Lucas Duboisse
##

NAME	=	libmy_malloc.so

SRC	=	src/malloc.c		\
		src/alloc_func.c	\
		src/heap_func.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wpadded -Wall -Wextra -shared -fpic -Iinclude/ -lm

all:		$(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
