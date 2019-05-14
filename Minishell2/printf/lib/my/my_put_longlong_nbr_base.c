/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** null
*/

#include "my.h"
#include <stdio.h>

void my_put_nbr_base_long(unsigned long number, char *base)
{
	unsigned long tmp = 0;
	unsigned long tmp_2 = 0;

	tmp = number % (my_strlen(base));
	tmp_2 = (number - tmp) / (my_strlen(base));
	if (tmp_2 != 0)
		my_put_nbr_base_long(tmp_2, base);
	my_putchar(base[tmp]);
}
