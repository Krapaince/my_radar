##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC_GEN		=	src/script/generator/entities.c				\
				src/script/generator/generator_toolbox.c	\
				src/script/generator/generator.c			\

SRC_MAIN	=	src/main.c									\

SRC			=	src/simulation/traffic_simulation.c			\
				src/simulation/simulation.c					\
				src/simulation/aircraft/update_list.c		\
				src/script/load_aircraft.c					\
				src/script/load_tower.c						\
				src/script/load.c							\
				src/script/error_entities.c					\
				src/script/error.c							\
				src/destroy_entities.c						\
				src/csfml/alloc_init_destroy.c				\
				src/csfml/create_window.c					\
				src/csfml/display.c							\
				src/csfml/display_entities.c				\
				src/csfml/event.c							\
				src/csfml/time_update.c						\
				src/quadtree/alloc_destroy.c				\
				src/quadtree/collision_detection.c			\
				src/quadtree/init.c							\
				src/quadtree/quadtree.c						\
				src/quadtree/toolbox.c						\
				src/script/generator/generator_toolbox.c	\

SRC_TEST	=	tests/lib/test_merge_str.c					\
				tests/lib/test_my_getnbr.c					\
				tests/lib/test_my_putchar.c					\
				tests/lib/test_my_putnbr.c					\
				tests/lib/test_my_putstr.c					\
				tests/lib/test_my_revstr.c					\
				tests/lib/test_my_strcat.c					\
				tests/lib/test_my_strcmp.c					\
				tests/lib/test_my_strcpy.c					\
				tests/lib/test_my_strdup.c					\
				tests/lib/test_my_strlen.c					\
				tests/src/script/test_error_entities.c		\
				tests/src/script/test_error.c				\
				tests/src/script/test_load_aircraft.c		\
				tests/src/script/test_load_tower.c			\
				tests/src/script/test_load.c				\
				tests/src/test_destroy_entities.c			\
				tests/src/quadtree/test_alloc_destroy.c		\

OBJ_GEN		=	$(SRC_GEN:.c=.o)

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

OBJ_SRC		=	$(SRC:.c=.o)

OBJ_TESTS	=	$(SRC_TEST:.c=.o)

NAME		=	my_radar

NAME_TESTS	=	unit_tests

NAME_GENERATOR = generator

CC			=	gcc

override CFLAGS	+=	-Wall -Wextra -Werror -I ./include

LIBFLAGS	=	-L ./lib -lmy

LIBSYSTEM	=	-lcsfml-graphics -lsfml-graphics -lcsfml-window -lsfml-window -lcsfml-system -lsfml-system -lm

TESTFLAGS	=	-lcriterion --coverage

$(NAME):$(OBJ_MAIN) $(OBJ_SRC)
	make -C lib/
	$(CC) $(OBJ_SRC) $(OBJ_MAIN) -o $(NAME) $(LIBFLAGS) $(LIBSYSTEM)

all:$(NAME)

clean:
	make -C ./lib clean
	rm -rf $(OBJ_TESTS) $(OBJ_MAIN) $(OBJ_SRC) $(OBJ_GEN)

fclean: clean
	make -C ./lib fclean
	rm -f $(NAME) $(NAME_TESTS) $(NAME_GENERATOR)

re:	fclean	all

tests_run: CFLAGS += $(TESTFLAGS)

tests_run:$(OBJ_SRC) $(OBJ_TESTS)
	make -C ./lib tests_run
	$(CC) $(OBJ_TESTS) $(OBJ_SRC) -o $(NAME_TESTS) $(LIBFLAGS) $(LIBSYSTEM) $(TESTFLAGS)
	./unit_tests

generator:$(OBJ_GEN)
	make -C ./lib
	$(CC) $(OBJ_GEN) -o $(NAME_GENERATOR) $(LIBFLAGS)

.PHONY:	all	clean	fclean	tests_run	generator