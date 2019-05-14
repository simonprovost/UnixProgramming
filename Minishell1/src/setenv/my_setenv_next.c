/*
** EPITECH PROJECT, 2017
** null
** File description:
** null
*/

#include "minishell.h"

int size_env_setenv(char **env)
{
	int i = 0;

	for (; env[i] != NULL ; i++);
	return (i);
}

char **malloc_each_case_setenv(char **e, char **nv, char **ir, info_t *i)
{
	int j = 0;

	for (; e[j] != NULL ; j++)
		nv[j] = malloc(sizeof(char *) * my_strlen(e[j]));
	(i->count_args >= 2) ?
	(nv[j] = malloc(sizeof(char *) * (my_strlen(ir[1])
	+ my_strlen(ir[2])) + 1)) :
	(nv[j] = malloc(sizeof(char *) * my_strlen(ir[1]) + 1));
	nv[j][0] = '=';
	return (nv);
}

char **fill_each_case_setenv(char **env, char **new_env)
{
	int j = 0;

	for (; env[j] != NULL ; j++)
		new_env[j] = env[j];
	return (new_env);
}