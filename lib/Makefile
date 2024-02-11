##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	src/merge_str.c				\
		src/my_getnbr.c				\
		src/my_strcat.c				\
		src/my_strcmp.c				\
		src/my_strcpy.c				\
		src/my_strdup.c				\
		src/my_strlen.c				\

OBJ     =   $(SRC:.c=.o)

NAME    =   libmy.a

CC      =   gcc

CFLAGS  =   -Wall -Werror -Wextra -I ../include

all:$(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean	all

tests_run:
	make CFLAGS="-Wall -Werror -Wextra --coverage -I ../include"

.PHONY:	all	clean	fclean	tests_run