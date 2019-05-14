##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

SRC	=  src/main.c \
	src/lib/print_env.c \
	src/lib/show_double_tab.c \
	src/lib/str_to_word_array.c \
	src/lib/fill_info.c \
	src/lib/my_strcat.c \
	src/lib/my_strcmp.c \
	src/lib/my_strncmp.c \
	src/env/my_env.c \
	src/exit/my_exit.c \
	src/exit/check_error_exit.c \
	src/setenv/my_setenv.c \
	src/setenv/check_env.c \
	src/setenv/handling_error.c \
	src/setenv/my_setenv_next.c \
	src/setenv/my_setenv_if_exist_next.c \
	src/unsetenv/my_unsetenv.c \
	src/lib/func_useful.c \
	src/cd/check_args_func.c \
	src/cd/error_fail_cd.c \
	src/cd/essential_func_to_cd.c \
	src/cd/find_func.c \
	src/cd/find_func_next.c \
	src/cd/malloc_fill_update.c \
	src/cd/main_cd.c \
	src/basic_shell_func/check_func.c \
	src/basic_shell_func/fill_init_var_value.c \
	src/basic_shell_func/find_func_next.c \
	src/basic_shell_func/found_func.c \
	src/basic_shell_func/loop_main_basic.c \
	src/basic_shell_func/show_func.c \
	src/fork_func/my_child.c \
	src/get_next_line/get_next_line.c \
	src/lib/my_strdup.c \
	src/basic_shell_func/next_access.c \
	src/basic_shell_func/next_show_func.c \
	src/cd/find_func_next_next.c \
	src/exit/my_exit_next.c \
	src/main_next.c \
	src/unsetenv/my_unsetenv_next.c \
	src/basic_shell_func/check_func_next.c \


OBJ	=	$(SRC:.c=.o)

CC	= 	gcc

NAME	=	mysh

CFLAGS	=	-I./printf/include -I./include -Wall -Wextra -W -g3

FLAGS	=	-L./printf/ -lmy

all:	prepare_lib $(NAME)

prepare_lib:
	make -C printf/

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(CFLAGS)
clean:
	make clean -C ./printf
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
