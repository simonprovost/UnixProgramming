/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** null
*/

#include "my.h"
#include <stdarg.h>

void print_my_zero(char *tmp, int i)
{
	if (tmp[i] >= 0 && tmp[i] <= 7) {
		my_putstr("0");
	}
}

void my_func_string_captals(char *str, va_list arguments)
{
	char *tmp = va_arg(arguments, char*);
	int i = 0;
	int c = 0;

	while (tmp[i] != '\0') {
		if (((tmp[i] > 0 && tmp[i] <= 32)||(tmp[i] == 127)) && c == 0) {
			my_putchar('\\');
			print_my_zero(tmp, i);
			my_putstr("0");
			my_put_nbr_base(tmp[i], "01234567");
			c++;
		} else {
			my_putchar(tmp[i]);
		}
		i++;
	}
	str++;
}
