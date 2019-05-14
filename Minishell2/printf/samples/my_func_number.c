/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** null
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>

void my_func_number(char *str, va_list new_arguments)
{
	int tmp = va_arg(new_arguments, int);
	va_list temporary_list;
	va_copy(temporary_list, new_arguments);
	char buff[my_strlen_int(tmp) + 1];
	my_itoa(tmp, buff);
	int check = 0;
	int i = 0;

	if (str[-1] != '%' && buff[0] == '-') {
		buff[0] = '0';
		check = 1;
	}
	if (check == 1) {
		while (buff[i]) {
			my_putchar(buff[i]);
			i++;
		}
	} else if (check == 0)
		my_put_nbr(tmp);
	str++;
}
