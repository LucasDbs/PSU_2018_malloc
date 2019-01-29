##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Lucas Duboisse
##

NAME	=	libmy_malloc.so

<<<<<<< HEAD
SRC	=	src/basics.c		\
		src/alloc_func.c
=======
SRC	=	src/main.c \
		src/malloc.c
>>>>>>> e1ecb1f2777656e5c7da6a275796ae02270948b9

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -W -Wall -Wextra -shared -fpic -Iinclude/ -lm

all:		$(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
