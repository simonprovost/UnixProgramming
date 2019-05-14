/*
** EPITECH PROJECT, 2018
** minishell1_2017
** File description:
** minishell1_2017 made by Sanchez Lucas
*/

#include "42sh.h"

void env_func(char **str, shell_t shell, int *ret_value)
{
	env_t *env = shell.env;

	if (str && str[1] != NULL) {
		my_printf("env: Expression Syntax.\n");
		*ret_value = 1;
		return;
	}
	while (env) {
		if (env->name && env->value)
			my_printf("%s=%s\n", env->name, env->value);
		else if (env->name && !env->value)
			my_printf("%s=\n", env->name);
		env = env->next;
	}
}
