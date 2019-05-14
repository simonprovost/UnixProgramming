/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** printf of EPITECH
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../../../include/my.h"

int scan_spec(va_list list, char *str, spec_t *spec)
{
	int i = 0;
	int j = 0;
	int nb = my_getnbr(str + 1);
	va_list new_list;

	while (i < 5) {
		if (str[0] == spec[i].c) {
			va_copy(new_list, list);
			j = spec[i].fptr(new_list, nb);
			va_end(new_list);
			return (j);
		}
		i++;
	}
	return (0);
}

void scan_tab(va_list list, char c, tab_t *print)
{
	int i = 0;

	while (i < 13) {
		if (c == print[i].c) {
			print[i].fptr(list);
			return;
		}
		i++;
	}
	my_putchar('%');
	my_putchar(c);
}

int my_printf(char *str, ...)
{
	int i = 0;
	va_list list;
	tab_t print[13];
	spec_t spec[5];

	func_init(print, spec);
	va_start(list, str);
	while (str[i]) {
		if (str[i] == '%') {
			i++;
			i += scan_spec(list, str + i, spec);
			scan_tab(list, str[i], print);
		} else
			my_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (i);
}
