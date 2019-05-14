/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** null
*/

#include "my.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void found_percent(char *str, int *i, va_list arguments)
{
	if (str[*i] == '%') {
		(*i)++;
		check_balise(arguments, str, i);
	} else {
		my_putchar(str[*i]);
	}
}

int my_printf(char *str, ...)
{
	int i = 0;
	va_list arguments;

	va_start(arguments, str);
	if (str != NULL) {
		while (str[i] != '\0') {
			found_percent(str, &i, arguments);
			i++;
			va_end(arguments);
		}
	}
	return (0);
}
