/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** null
*/

#include "my.h"
#include <stdarg.h>

void my_put_nbr_utod(long unsigned number)
{
	int tmp;

	tmp = (number % 10);
	number = (number - tmp) / 10;
	my_put_nbr(number);
	my_putchar(tmp + '0');
}

void my_func_utod(char *str, va_list arguments)
{
	unsigned number = va_arg(arguments, unsigned);

	my_put_nbr_utod(number);
	str++;
}
