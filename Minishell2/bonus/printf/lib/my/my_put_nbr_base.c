/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** null
*/

#include "my.h"

void my_put_nbr_base(int number, char *base)
{
	int tmp = 0;
	int tmp_2 = 0;

	if (number < 0) {
		my_putchar('-');
		my_put_nbr_base((-number), base);
	}
	if (number >= 0) {
		tmp = number % (my_strlen(base));
		tmp_2 = (number - tmp) / (my_strlen(base));
		if (tmp_2 != 0)
			my_put_nbr_base(tmp_2, base);
		my_putchar(base[tmp]);
	}
}
