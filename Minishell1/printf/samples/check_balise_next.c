/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** null
*/

#include "my.h"

void check_balise_next(int g_tab_found, int size, char *str, int *i)
{
	if ((g_tab_found != 1) && size == 0) {
		my_putchar(str[*i - 1]);
		my_putchar(str[*i]);
	}
}
