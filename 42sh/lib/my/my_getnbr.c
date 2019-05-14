/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** .c
*/

#include <stdio.h>
#include <limits.h>

int my_getnbr(char const *str)
{
	long nb = 0;
	int nb_neg = 1;
	int i = 0;

	for (; str[i] == '-' || str[i] == '+'; i++)
		(str[i] == '-' ? nb_neg *= -1 : 0);
	for (; str[i] >= '0' && str[i] <= '9'; i++)
		nb = nb * 10 + str[i] - 48;
	(nb > INT_MAX || nb < INT_MIN ? nb = 0 : nb);
	return ((nb_neg == -1 ? nb *= -1 : nb));
}
