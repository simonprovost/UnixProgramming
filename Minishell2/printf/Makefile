##
## EPITECH PROJECT, 2017
## my_printf
## File description:
## null
##

SRC	=	lib/my/my_put_nbr.c \
		lib/my/my_putchar.c \
		lib/my/my_putstr.c \
		lib/my/my_strlen.c \
		lib/my/my_put_nbr_base.c \
		lib/my/my_getnbr.c \
		lib/my/my_strlen_int.c \
		lib/my/my_put_longlong_nbr_base.c \
		lib/my/my_calloc.c \
		lib/my/show_double.c \
		samples/begin_balise.c \
		samples/check_func.c \
		samples/my_func_charac.c \
		samples/my_func_number.c \
		samples/my_func_string.c \
		samples/my_func_string_captals.c \
		samples/my_func_utod.c \
		samples/my_func_dtoo.c \
		samples/my_func_dtox.c \
		samples/my_func_dtob.c \
		samples/my_func_dto_captalx.c \
		samples/my_func_ptoh.c \
		samples/my_func_percent.c \
		samples/check_specifiers.c \
		samples/my_printf.c \
		samples/check_specifiers_string.c \
		samples/my_itoa.c \
		samples/check_func_spec_point.c \
		samples/check_spec_next.c \
		samples/check_balise_next.c \
		samples/my_fill_string.c \
		samples/check_hastag.c \
		samples/my_func_float.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

NAME.H	=	my.h

CFLAGS	=	-I./include -Wall -Wextra -W -g -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re : fclean all
