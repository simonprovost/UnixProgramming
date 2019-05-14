/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

char *my_strdup(char *str)
{
	char *copy = NULL;

	if (str != NULL) {
		copy = malloc(sizeof(char) * (my_strlen(str) + 1));
		if (copy != NULL)
			return (my_strcpy(copy, str));
	}
	free (copy);
	return (NULL);
}