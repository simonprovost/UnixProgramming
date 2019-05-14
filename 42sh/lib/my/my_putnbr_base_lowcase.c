/*
** EPITECH PROJECT, 2017
** my_putnbr_base
** File description:
** put nbr to base
*/

#include "../../include/my.h"

void my_putchar(char c);

void my_putnbr_base_lowcase(long long nbr, int base)
{
	int res = 0;
	char *base_data = "0123456789abcdef";

	if (nbr < 0) {
		nbr *= -1;
		my_putchar('-');
	}
	if (nbr > base - 1)
		my_putnbr_base_lowcase(nbr / base, base);
	my_putchar(base_data[nbr % base]);
}
