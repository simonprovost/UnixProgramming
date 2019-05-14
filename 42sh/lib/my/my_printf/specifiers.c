/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** specifiers printf
*/

#include <stdarg.h>
#include "../../../include/my.h"

int spec_zero(va_list list, int nbr_zero)
{
	int i = 1;
	int j = 2;
	int p = nbr_zero;
	long long nbr = va_arg(list, int);

	for (; p > 9; j++)
		p /= 10;
	if (nbr < 0)
		return (j);
	for (; nbr > 9; i++)
		nbr /= 10;
	nbr_zero -= i;
	for (; nbr_zero > 0; nbr_zero--)
		my_putchar('0');
	return (j);
}

int spec_space(va_list list, int nbr_space)
{
	int i = 0;
	int j = 2;
	int p = nbr_space;
	long long nbr = va_arg(list, long long);

	my_putchar(' ');
	if (p == 0)
		return (1);
	for (; p > 9; j++)
		p /= 10;
	if (nbr < 0)
		return (j);
	for (; nbr > 9; i++)
		nbr /= 10;
	nbr_space -= i;
	for (; nbr_space - i > 0; nbr_space--)
		my_putchar(' ');
	return (j);
}

int spec_plus(va_list list, int nb)
{
	int i = 0;
	int j = 2;
	int calc = 0;
	long long arg = va_arg(list, long long);

	if (nb == 0) {
		my_putchar('+');
		return (1);
	}
	for (; arg > 9; i++)
		arg /= 10;
	calc = nb - i - 2;
	while (calc > 0) {
		my_putchar(' ');
		calc--;
	}
	for (; nb > 9; j++)
		nb /= 10;
	my_putchar('+');
	return (j);
}

int spec_minus(va_list list, int nb)
{
	(void) list;
	(void) nb;

	return (1);
}

int spec_hashtag(va_list list, int nb)
{
	int i = 0;
	int j = 2;
	int calc = 0;
	long long nbr = va_arg(list, long long);

	my_putstr("0X");
	if (nb == 0)
		return (1);
	for (; nbr > 9; i++)
		nbr /= 10;
	calc = nb - i - 2;
	while (calc > 0) {
		my_putchar(' ');
		calc--;
	}
	for (; nb > 9; j++)
		nb /= 10;
	return (j);
}
