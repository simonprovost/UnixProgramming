/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** null
*/

#include "my.h"

void my_func_float(char *str, va_list arguments)
{
	float tmp = va_arg(arguments, double);

	show_double(tmp, 2);
	str++;
}
