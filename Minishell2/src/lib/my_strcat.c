/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** .c
*/

#include "minishell.h"

char *my_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	char *tm = NULL;

	if (!dest || !src)
		return (NULL);
	tm = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 1);
	while (i < my_strlen(dest)) {
		tm[i] = dest[i];
		i++;
	}
	while (j < my_strlen(src)) {
		tm[i] = src[j];
		j++;
		i++;
	}
	tm[i] = '\0';
	return (tm);
}
