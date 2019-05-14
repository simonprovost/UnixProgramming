/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** null
*/

#include "my.h"
#include <stdarg.h>

void my_func_dtoo(char *str, va_list arguments)
{
	int tmp = va_arg(arguments, int);

	my_put_nbr_base(tmp, "01234567");
	str++;
}
