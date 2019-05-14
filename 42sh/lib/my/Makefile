##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile that compiles my library into /lib
##

CC	=	gcc -g3

SRC	=	my_getnbr.c			\
		my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_strlen.c			\
		my_putnbr_base.c		\
		my_putnbr_base_lowcase.c	\
		my_printf/my_printf.c		\
		my_printf/init.c		\
		my_printf/char.c		\
		my_printf/int.c			\
		my_printf/special_characters.c	\
		my_printf/str.c			\
		my_printf/specifiers.c		\
		my_printf/float.c		\
		int_to_str.c			\
		my_strcat.c			\
		my_str_to_word_array.c		\
		my_strcmp.c			\
		my_strdup_2d_array.c		\
		my_strncmp.c			\
		my_strdup.c			\
		my_str_isalpha.c		\
		my_str_isnum.c			\
		get_next_line.c			\
		my_free_tab.c			\
		my_tablen.c			\
		my_clean_str.c			\
		convert_tab.c			\
		print_tab.c			\


OBJ	=	$(SRC:.c=.o)


NAME	=	libmy.a


all: 	$(NAME)


$(NAME):	$(OBJ)
	rm -f $(NAME)
	ar rc $(NAME) $(OBJ)


clean:
	rm -f $(OBJ)
