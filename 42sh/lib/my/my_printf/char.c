/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** database for printf
*/

#include "../../.././include/my.h"

void my_put_char(va_list list)
{
	my_putchar((char)va_arg(list, int));
}
