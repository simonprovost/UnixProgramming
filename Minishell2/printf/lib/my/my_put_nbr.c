/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** null
*/

#include "my.h"
#include <stdio.h>

int check_if_negaitf(long int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb *= (-1);
	}
	return (nb);
}

void recursv_put(int nb)
{
	if (nb != 0)
		my_put_nbr(nb);
}

void my_put_nbr(int nb)
{
	int modulo;

	nb = check_if_negaitf(nb);
	if (nb >= 0) {
		if (nb >= 10) {
			modulo = (nb % 10);
			nb = (nb) / 10;
			recursv_put(nb);
			my_putchar(modulo + '0');
		} else
			my_putchar(nb % 10 + '0');
	}
}
