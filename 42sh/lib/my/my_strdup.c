/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** PSU_minishell1_2017 made by Sanchez Lucas
*/

#include <stdlib.h>

char *my_strdup(char *str)
{
	char *dup_str = NULL;
	int i = 0;

	if (!str)
		return (NULL);
	while (str[i])
		i++;
	dup_str = malloc(sizeof(char) * (i + 1));
	for (int j = 0; str[j]; j++)
		dup_str[j] = str[j];
	dup_str[i] = 0;
	return (dup_str);
}
