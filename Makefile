##
## EPITECH PROJECT, 2018
## 103cipher_2018
## File description:
## Makefile
##

SRC	=	main.c	\
		first_function.c	\
		second_function.c	\
		third_function.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -g3 -ggdb -I ./include

NAME	=	103cipher

all:		$(NAME)	message

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

message:
		@echo "SUCCESFULY COMPILED!"
