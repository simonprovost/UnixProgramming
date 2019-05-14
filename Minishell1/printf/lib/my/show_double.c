/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** null
*/

#include <stdio.h>
#include "my.h"

void show_long(long nb)
{
	if (nb == 0)
		my_putchar('0');
	if (nb / 10)
		show_long(nb / 10);
	my_putchar(nb % 10 + '0');
}

void show_double(float nb, int precision)
{
	long tmp = nb;

	if (nb < 0) {
		my_putchar('-');
		show_double(-nb, precision);
	}
	show_long(tmp);
	my_putchar('.');
	while (precision--) {
		nb = ((nb - tmp) * 10);
		tmp = nb + 0.1;
		show_long(tmp);
	}
}
