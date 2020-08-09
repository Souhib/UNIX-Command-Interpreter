##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC     =       src/main.c	\
		src/builtin.c	\
		src/cd.c	\
		src/env.c	\
		src/input.c	\
		src/set_path.c	\

OBJ     =       $(SRC:.c=.o)

NAME    =       mysh

CC      =       gcc -std=gnu99

CFLAGS	+=	-I ./include/

CPPFLAGS	+=	-Wall -Wextra

LIB	=	-L. lib/libmy.a lib/libgnl.a

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/ all
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	make clean -C lib/my/
	rm -rf *~
	rm -rf src/*~
	rm -rf src/*.o

fclean: clean
	make fclean -C lib/my/
	rm -rf $(NAME)

re:     fclean all

.PHONY: all clean fclean re
