/*
** EPITECH PROJECT, 2017
** my_strcmp
** File description:
** .c
*/

#include "minishell.h"

int my_strcmp(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (1);
	if (my_strlen(s1) != my_strlen(s2))
		return (1);
	for (int i = 0; s1[i]; i++) {
		if (s1[i] != s2[i])
			return (1);
	}
	return (0);
}
