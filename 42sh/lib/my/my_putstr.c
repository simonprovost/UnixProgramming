/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** displaying characters of a strinf one by one
*/

#include <stdlib.h>

void my_putchar(char);

int my_putstr(char const *str)
{
	int i = 0;

	while (str[i]) {
		my_putchar(str[i]);
		i++;
	}
	return (0);
}
