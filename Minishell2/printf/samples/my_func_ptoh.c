/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** null
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>

void my_func_ptoh(char *str, va_list arguments)
{
	char *tmp = va_arg(arguments, char *);
	unsigned long adr = (unsigned long)tmp;

	if (adr != 0) {
		my_putstr("0x");
		my_put_nbr_base_long(adr, "0123456789abcdef");
	} else {
		my_putstr("(nil)");
	}
	str++;
}
