/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** database for printf
*/

#include "../../../include/my.h"

void my_put_int(va_list list)
{
	my_put_nbr(va_arg(list, int));
}

void my_putnbr_hexa(va_list list)
{
	my_putnbr_base(va_arg(list, int), "0123456789ABCDEF");
}

void my_putnbr_hexa_lowcase(va_list list)
{
	my_putnbr_base_lowcase(va_arg(list, int), 16);
}

void my_putnbr_octal(va_list list)
{
	my_putnbr_base(va_arg(list, int), "01234567");
}

void my_putnbr_binary(va_list list)
{
	my_putnbr_base(va_arg(list, int), "01");
}
