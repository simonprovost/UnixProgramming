/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** null
*/

#include "my.h"

void begin_balise(char *str, int *i)
{
	if (str[*i] == '#')
		check_hastag(str, i);
}
