/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** null
*/

#include "my.h"

void my_calloc(char *tmp, char *str)
{
	int j = 0;

	while (j < my_strlen(str)) {
		tmp[j] = '0';
		j++;
	}
	tmp[j] = '\0';
}
