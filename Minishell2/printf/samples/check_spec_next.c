/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** null
*/

#include "my.h"

void check_spec_next(int *k, char *tmp, char *str, int*i)
{
	int j = 0;

	while (j < my_strlen(str) + 1) {
		tmp[j] = '0';
		j++;
	}
	while (str[*i] >= '0' && str[*i] <= '9') {
		tmp[*k] = str[*i];
		(*i)++;
		(*k)++;
	}
}
