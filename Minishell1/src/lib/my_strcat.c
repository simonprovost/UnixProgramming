/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** .c
*/

#include "minishell.h"

char *my_strcat_shell(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	char *tmp = malloc(sizeof(char) * my_strlen(dest) +
	my_strlen(src) + 2);

	while (i < my_strlen(dest)) {
		tmp[i] = dest[i];
		i++;
	}
	if (dest[my_strlen(dest) - 1] != '/') {
		tmp[i] = '/';
		i++;
	}
	while (j < my_strlen(src)) {
		tmp[i] = src[j];
		j++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
