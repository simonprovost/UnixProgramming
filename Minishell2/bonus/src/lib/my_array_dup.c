/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

char **my_array_dup(char **env)
{
	int len = count_env(env);
	char **tmp = malloc(sizeof(char *) * (len + 1));
	int i = 0;
	int j = 0;

	for (; env[i] != NULL ; i++) {
		tmp[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
		for (j = 0 ; env[i][j] != 0 ; j++)
			tmp[i][j] = env[i][j];
		tmp[i][j] = '\0';
	}
	tmp[i] = NULL;
	return (tmp);
}