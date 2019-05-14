/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

char *my_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i]) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
