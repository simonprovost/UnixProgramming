##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##
SRC = 	$(wildcard *.c) \
	$(wildcard src/*.c) \
	$(wildcard src/lib/*.c) \
	$(wildcard src/shell_lib/*.c) \
	$(wildcard src/get_next_line/*.c) \
	$(wildcard src/hash_lib/src/*.c) \
	$(wildcard src/hash_lib/src/hm/*.c) \
	$(wildcard src/builtin_and_no_builtin/*.c) \
	$(wildcard src/builtin_and_no_builtin/builtin/*.c) \
	$(wildcard src/free_func/*.c) \
	$(wildcard src/builtin_and_no_builtin/no_builtin*.c) \
	$(wildcard src/builtin_and_no_builtin/no_builtin/cd/*.c) \
	$(wildcard src/builtin_and_no_builtin/no_builtin/env/*.c) \
	$(wildcard src/builtin_and_no_builtin/no_builtin/exit/*.c) \
	$(wildcard src/builtin_and_no_builtin/no_builtin/setenv/*.c) \
	$(wildcard src/builtin_and_no_builtin/no_builtin/unsetenv/*.c) \
	$(wildcard src/builtin_and_no_builtin/no_builtin/*.c) \
	$(wildcard src/binary_tree/*.c) \
	$(wildcard src/redirection/*.c) \
	$(wildcard src/redirection/error_handling/*.c) \
	$(wildcard src/redirection/parser/*.c) \
	$(wildcard src/redirection/left_redi/*.c) \
	$(wildcard src/redirection/semicolon/*.c) \
	$(wildcard src/redirection/right_redi/*.c) \
	$(wildcard src/redirection/pipe/*.c) \

_END=$'\x1b[0m'
_RED=$'\x1b[31m'

OBJ =	$(SRC:%.c=%.o)

CC	= 	gcc

NAME	=	mysh

CFLAGS	=	-I./printf/include -I./include -Wall -Wextra -W -g3 -I./

FLAGS	=	-L./printf/ -lmy

all:	prepare_lib $(NAME)

prepare_lib:
	make -C printf/

NO_OF_FILES := $(words $(SRC))

$(NAME):	$(OBJ)
	@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;35m$(NO_OF_FILES)\033[0m"
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(CFLAGS)
	@ echo "\033[1;31m ------------------Name of Binary : \033[1;35m$(NAME)\033[0;31m®\033[1;31m Created Sucesfully ------------------\033[0m"

clean:
	make clean -C ./printf
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

%.o:	%.c
	@ echo "\033[1;35m[ OK ]\033[0m Compiling" $<
	@ $(CC) -o $@ -c $< $(CFLAGS)

.SILENT: