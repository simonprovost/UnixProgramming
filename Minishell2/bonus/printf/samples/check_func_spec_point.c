/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** null
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void func_spec_next(int *size, int count_charac_args)
{
	int count = 0;

	while (count < (*size - count_charac_args)) {
		my_putchar('0');
		count++;
	}
}
void check_func_spec_point(char *str, int *i, va_list arguments, int *size)
{
	va_list new_list;
	int tmp = 0;
	int count_charac_args = 0;
	va_copy(new_list, arguments);

	if (str[*i] == 'd') {
		tmp = va_arg(new_list, int);
		count_charac_args = my_strlen_int(tmp);
		if (*size > count_charac_args) {
			func_spec_next(size, count_charac_args);
			(*size) = 0;
		}
	}
	va_end(new_list);
}
