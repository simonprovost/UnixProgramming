/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** database for printf
*/

#include "../../../include/my.h"

void my_put_ampersand(va_list list)
{
	(void)list;

	my_putchar('%');
}

void my_put_unsigned(unsigned int nb)
{
	int res = 0;

	if (nb > 9)
		my_put_unsigned(nb / 10);
	res = nb % 10;
	my_putchar(res + 48);
}

void my_put_unsigned_int(va_list list)
{
	unsigned int nb = va_arg(list, unsigned int);

	my_put_unsigned(nb);
}

void my_put_pointer_adress(va_list list)
{
	unsigned long long tmp = va_arg(list, unsigned long long);

	if (tmp == 0)
		my_putstr("(nil)");
	my_putstr("0x");
	my_putnbr_base_lowcase(tmp, 16);
}
