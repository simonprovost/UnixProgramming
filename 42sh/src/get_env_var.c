/*
** EPITECH PROJECT, 2018
** minishell1_2017
** File description:
** minishell1_2017 made by Sanchez Lucas
*/

#include "42sh.h"

char *get_env(env_t *env, char *name)
{
	while (env) {
		if (env->name && !my_strcmp(env->name, name))
			break;
		env = env->next;
	}
	if (env == NULL)
		return (NULL);
	return (env->value);
}