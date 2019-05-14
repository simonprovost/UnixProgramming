/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** null
*/

#include "my.h"
#include <stdarg.h>

void my_func_dtox(char *str, va_list arguments)
{
	int tmp = va_arg(arguments, int);

	my_put_nbr_base(tmp, "0123456789abcdef");
	str++;
}
