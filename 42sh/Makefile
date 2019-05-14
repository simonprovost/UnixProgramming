##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	= 	src/main.c						\
		src/sig.c						\
		src/local_var/add_lvar.c				\
		src/local_var/create_lvar.c				\
		src/local_var/sort_lvar.c				\
		src/local_var/too_deep.c				\
		src/local_var/unset.c					\
		src/local_var/get_lvar.c				\
		src/alias/unalias.c					\
		src/alias/alias.c					\
		src/alias/alias_loop.c					\
		src/alias/create_alias.c				\
		src/alias/get_alias.c					\
		src/alias/sort_alias.c					\
		src/loop.c						\
		src/prompt.c						\
		src/concat_exec.c					\
		src/built_ins/check_built_ins.c				\
		src/built_ins/cd.c					\
		src/built_ins/exit.c					\
		src/built_ins/setenv.c					\
		src/built_ins/unsetenv.c				\
		src/built_ins/env.c					\
		src/built_ins/echo.c					\
		src/built_ins/repeat.c					\
		src/built_ins/if.c					\
		src/built_ins/if_then.c					\
		src/built_ins/parser_if.c				\
		src/built_ins/utils_if.c				\
		src/built_ins/where.c					\
		src/built_ins/which.c					\
		src/built_ins/foreach.c					\
		src/built_ins/utils_foreach.c				\
		src/linked_list.c					\
		src/exec.c						\
		src/get_env_var.c					\
		src/verif_env.c						\
		src/check_segfault.c					\
		src/create_env.c					\
		src/pwd_changes.c					\
		src/binary_tree.c					\
		src/parser/parsing_cmd.c				\
		src/parser/parsing_or.c					\
		src/parser/parsing_and.c				\
		src/parser/parsing_pipes_and_redirections.c		\
		src/parser/error_handling.c				\
		src/parser/parse_quotes.c				\
		src/parser/inhibitors.c					\
		src/parser/globbing/glob.c				\
		src/parser/globbing/process/process_glob.c		\
		src/parser/globbing/process/process_parser_glob.c	\
		src/parser/globbing/process/error_glob.c		\
		src/set_pipefd.c					\
		src/exec_tree/exec_tree.c				\
		src/exec_tree/exec_pipe.c				\
		src/exec_tree/exec_redirect.c				\
		src/exec_tree/exec_separator.c				\
		src/exec_tree/exec_double_left_redirect.c		\
		src/parser/parse_env_variables.c			\
		src/scripting.c						\
		src/error_handling_if.c					\
		src/func_error_handling_if.c				\

OBJ	=	$(SRC:.c=.o)

CC	= 	gcc -Wextra -Wall -Werror -no-pie

_END=$'\x1b[0m'
_RED=$'\x1b[31m'

NO_OF_FILES 	:=	 $(words $(SRC))

NAME		=	42sh

LIB_NAME	=	libmy.a

FLAGS		=	-L./lib/my -lmy

CFLAGS		=	-I./include

all:	prepare_lib $(NAME)

tests_run: prepare_lib
	make -C tests/
	tests/unit-tests

prepare_lib:
	make -C lib/my

$(NAME):	$(OBJ)
	@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;35m$(NO_OF_FILES)\033[0m"
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(CFLAGS)
	@ echo "\033[1;35m ------------------Name of Binary : \033[1;31m$(NAME)\033[0;31m®\033[1;35m Created Sucesfully ------------------\033[0m"

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean:	clean
	rm -f lib/my/$(LIB_NAME)
	rm -f $(NAME)

re:	fclean all

%.o:	%.c
	@ echo "\033[1;35m[ OK ]\033[0m Compiling" $<
	@ $(CC) -o $@ -c $< $(CFLAGS)

.SILENT: