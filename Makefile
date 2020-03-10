##
## EPITECH PROJECT, 2020
## PSU_tetris_2019
## File description:
## Project makefile
##

DSRC	=	./src/

SRC	=	$(DSRC)main.c						\
		$(DSRC)constant.c					\
		$(DSRC)usage.c						\
		$(DSRC)tools.c						\
		$(DSRC)game/tetris.c				\
		$(DSRC)prepare/game_init.c			\
		$(DSRC)prepare/get_config.c			\
		$(DSRC)prepare/config/config_apply_options.c	\
		$(DSRC)prepare/load_tetriminos.c	\
		$(DSRC)prepare/debug_display_config.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	LIB $(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

LIB:
	make -C ./lib/my

clean:
	rm -f  $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#tests_run:
#gcc -o $(NAME) $(SRC_UT) -I./include -L./lib/my -lmy -lcriterion --coverage && ./$(NAME)

.PHONY :        clean fclean re