##
## EPITECH PROJECT, 2021
## my runner
## File description:
## Make a runner game
##

SRC	=	$(wildcard src/*.c) $(wildcard src/*/*.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -pedantic -I./include

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) $(CFLAGS) -g3 -lcsfml-graphics -lcsfml-audio \
		-lcsfml-system
		make clean

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
