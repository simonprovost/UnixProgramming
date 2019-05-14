/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** null
*/

#include "my.h"

char *my_fill_string(char *tmp, char *src, int size)
{
	int i = 0;

	while (i < my_strlen(src) - size) {
		tmp[i] = src[i];
		i++;
	}
	return (tmp);
}
