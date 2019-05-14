/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** null
*/

#include "my.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void spec_space_zero(int check_zero)
{
	if (check_zero == 1)
		my_putchar('0');
	else if (check_zero == 0)
		my_putchar(' ');
}

void check_specifiers_string(char *tmp, va_list arguments, int check_zero)
{
	int count = my_getnbr(tmp);
	int j = 0;
	va_list temporary_list;
	va_copy(temporary_list, arguments);
	char *tmp_list = va_arg(temporary_list, char *);

	if (tmp != NULL) {
		while (j < count - my_strlen(tmp_list)) {
			spec_space_zero(check_zero);
			j++;
		}
	}
}
