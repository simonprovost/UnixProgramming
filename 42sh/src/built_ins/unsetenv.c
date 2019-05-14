/*
** EPITECH PROJECT, 2018
** minishell1_2017
** File description:
** minishell1_2017 made by Sanchez Lucas
*/

#include "42sh.h"

void unset_var(env_t *env, char *var)
{
	env_t *tmp = env;

	while (env->next != NULL) {
		tmp = env->next;
		if (env->next->name && my_strcmp(var, env->next->name) == 0) {
			env->next = env->next->next;
			free(tmp->name);
			free(tmp->value);
			free(tmp);
			break;
		}
		env = env->next;
	}
}

void unsetenv_func(char **str, shell_t shell, int *ret_value)
{
	int i = 1;

	if (my_tablen(str) == 1) {
		my_printf("%s: Too few arguments.\n", str[0]);
		*ret_value = 1;
	} else {
		while (str[i] != NULL) {
			unset_var(shell.env, str[i]);
			i++;
		}
	}
}
