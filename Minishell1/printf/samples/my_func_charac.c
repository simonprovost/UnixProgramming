/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** null
*/

#include "my.h"
#include <stdarg.h>

void my_func_charac(char *str, va_list arguments)
{
	char tmp = va_arg(arguments, int);

	my_putchar(tmp);
	str++;
}
