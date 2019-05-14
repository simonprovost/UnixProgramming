/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** database for printf
*/

#include "../../../include/my.h"

void my_put_str(va_list list)
{
	my_putstr(va_arg(list, char *));
}

void find_number(char c)
{
	int i = 0;

	while (i != c)
		i++;
	if (i < 8)
		my_putstr("00");
	else if ((i >= 8 && i < 32) || i == 127)
		my_putchar('0');
	my_putnbr_base(i, "01234567");
}

void my_put_str_non_printable(va_list list)
{
	int i = 0;
	char *str = va_arg(list, char *);

	while (str[i]) {
		if (str[i] < 32 || str[i] >= 127) {
			my_putchar('\\');
			find_number(str[i]);
		} else
			my_putchar(str[i]);
		i++;
	}
}
