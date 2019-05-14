/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** PSU_my_printf_2017 made by Sanchez Lucas
*/

#include <stdarg.h>
#include "../../../include/my.h"

void my_put_float(va_list list)
{
	double nbr = va_arg(list, double);
	int nb = nbr;
	int i = 6;

	my_put_nbr(nb);
	my_putchar('.');
	while (nbr > nb || i > 0) {
		nbr *= 10;
		nb = nbr;
		if (i == 1 && (int)(nbr * 10) % 10 > 4)
			my_putchar(nb % 10 + 49);
		else
			my_putchar(nb % 10 + 48);
		i--;
	}
}
