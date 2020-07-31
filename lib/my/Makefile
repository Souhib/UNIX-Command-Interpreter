##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 11h50
##

SRC	 = 		my_putchar.c	\
			my_putstr.c	\
			my_strlen.c	\
			my_putnbr.c	\
			my_strcpy.c	\
			my_strcat.c	\
			my_strcmp.c	\
			my_putunbr.c	\
			my_printf.c	\
			my_getnbr.c	\
			my_cutstr.c	\
			pur_str.c	\
			str_to_array.c	\
			my_swap.c	\
			my_new_strcpy.c	\

OBJ	=		$(SRC:.c=.o)

NAME	=		../libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -c $(SRC) -I ./../../include
		ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PNONY: all clean fclean re
