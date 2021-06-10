##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	lib/is_char_alpha.c	\
		lib/my_atoi.c	\
		lib/my_count_words.c	\
		lib/my_getnbr.c	\
		lib/my_nbrlen.c	\
		lib/my_printf.c	\
		lib/my_put_nbr.c	\
		lib/my_putchar.c	\
		lib/my_putstr.c	\
		lib/my_str_world.c	\
		lib/my_strcat.c	\
		lib/my_strcmp.c	\
		lib/my_strcpy.c	\
		lib/my_strdup.c	\
		lib/my_strlen.c	\
		lib/my_strncat.c	\
		lib/my_strncmp.c	\
		lib/realloc.c	\
		src/event_managment.c	\
		src/init_game.c	\
		src/run_game.c	\
		src/enemies.c	\
		src/towers.c	\
		src/fire.c	\
		src/tools.c	\
		src/tools2.c	\
		src/main.c

SRC2	=	is_char_alpha.c	\
		my_atoi.c	\
		my_count_words.c	\
		my_getnbr.c	\
		my_nbrlen.c	\
		my_printf.c	\
		my_put_nbr.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_str_world.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_strlen.c	\
		my_strncat.c	\
		my_strncmp.c	\
		realloc.c	\
		event_managment.c	\
		init_game.c	\
		run_game.c	\
		enemies.c	\
		towers.c	\
		fire.c	\
		tools.c	\
		tools2.c	\
		main.c

OBJ	=	$(SRC2:.c=.o)

NAME	=	defender

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	gcc -o $(NAME) $(OBJ)  -Wall -Werror -Wextra -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm
	rm -f $(OBJ)
clean:
	rm -f $(OBJ)
	rm -f *~
	rm -rf *.o
fclean:clean
	rm -rf *~ *# $(NAME)

re:	fclean all
