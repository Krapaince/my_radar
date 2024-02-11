##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC_GEN		=	src/generator/generator.c		\

SRC_MAIN	=	src/main.c						\

SRC			=	src/init.c						\
				src/color_smooth_random.c		\

SRC_TEST	=	tests/lib/test_merge_str.c		\
				tests/lib/test_my_getnbr.c		\
				tests/lib/test_my_strcat.c		\
				tests/lib/test_my_strcmp.c		\
				tests/lib/test_my_strcpy.c		\
				tests/lib/test_my_strlen.c		\

OBJ_GEN		=	$(SRC_GEN:.c=.o)

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

OBJ_SRC		=	$(SRC:.c=.o)

OBJ_TESTS	=	$(SRC_TEST:.c=.o)

NAME		=	my_radar

NAME_TESTS	=	unit_tests

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I ./include

LIBFLAGS	=	-L ./lib -lmy

LIBSYSTEM	=	-lcsfml-graphics -lcsfml-window -lsfml-window -lsfml-graphics -lsfml-system -lcsfml-system -lm

TESTFLAGS	=	-lcriterion --coverage

all:$(NAME)

$(NAME):$(OBJ_MAIN) $(OBJ_SRC)
	make -C lib/
	$(CC) $(OBJ_SRC) $(OBJ_MAIN) -o $(NAME) $(LIBFLAGS) $(LIBSYSTEM)

clean:
	make -C ./lib clean
	rm -rf $(OBJ_TESTS) $(OBJ_MAIN) $(OBJ_SRC) $(OBJ_GEN)

fclean: clean
	make -C ./lib fclean
	rm -f $(NAME) $(NAME_TESTS)

re:	fclean	all

tests_run:$(OBJ_TESTS)
	make -C ./lib tests_run
	$(CC) $(OBJ_TESTS) -o $(NAME_TESTS) $(LIBFLAGS) $(LIBSYSTEM) $(TESTFLAGS)
	./unit_tests

generator:
	make -C ./lib
	$(CC) $(OBJ_GEN) -o generator $(LIBFLAGS)

.PHONY:	all	clean	fclean	tests_run	generator