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

void spec_zero_space(int check_zero)
{
	if (check_zero == 1)
		my_putchar('0');
	else if (check_zero == 0)
		my_putchar(' ');
}

void check_specifiers(char *tmp, va_list arguments, int check_zero)
{
	int count = my_getnbr(tmp);
	int j = 0;
	va_list temporary_list;
	va_list temporary_list_2;
	va_copy(temporary_list, arguments);
	va_copy(temporary_list_2, arguments);
	int tmp_int = va_arg(temporary_list, int);
	char buff[my_strlen_int(tmp_int) + 1];
	my_itoa(tmp_int, buff);

	if (tmp != NULL) {
		if (buff[0] == '-') {
			my_putchar('-');
			j++;
		}
		while (j < count - my_strlen(buff)) {
			spec_zero_space(check_zero);
			j++;
		}
	}
}
