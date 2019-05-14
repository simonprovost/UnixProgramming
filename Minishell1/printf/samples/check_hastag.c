/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** null
*/

#include "my.h"

void check_hastag(char *str, int *i)
{
	if (str[*i + 1] == 'o') {
		my_putchar('0');
		str++;
		(*i)++;
	} else if (str[*i + 1] == 'x' || str[*i + 1] == 'X') {
		my_putstr("0x");
		str++;
		(*i)++;
	}
}
