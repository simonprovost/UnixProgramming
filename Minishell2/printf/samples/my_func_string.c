/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** null
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>

void my_func_string(char *str, va_list arguments)
{
	char *tmp = va_arg(arguments, char*);

	if (!tmp)
		my_putstr("(null)");
	else
		my_putstr(tmp);
	str++;

}
