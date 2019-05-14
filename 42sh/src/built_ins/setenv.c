/*
** EPITECH PROJECT, 2018
** minishell1_2017
** File description:
** minishell1_2017 made by Sanchez Lucas
*/

#include "42sh.h"

int verif_name_var(char *name)
{
	if (name == NULL)
		return (0);
	if (name[0] >= '0' && name[0] <= '9')
		return (1);
	for (int i = 0; name[i]; i++) {
		if ((name[i] < '0' || name[i] > '9')
		&& (name[i] < 'a' || name[i] > 'z')
		&& (name[i] < 'A' || name[i] > 'Z'))
			return (2);
	}
	return (0);
}

int find_existing_elem(env_t *env, char *name, char *value)
{
	while (env) {
		if (env->name && !my_strcmp(name, env->name) && env->value) {
			free(env->value);
			env->value = my_strdup(value);
			return (1);
		} else if (env->name && !my_strcmp(name, env->name)) {
			env->value = my_strdup(value);
			return (1);
		}
		env = env->next;
	}
	return (0);
}

void add_elem_to_env(env_t *env, char *name, char *value)
{
	env_t *new_elem = malloc(sizeof(*new_elem));

	if (find_existing_elem(env, name, value) == 1)
		return;
	new_elem->name = my_strdup(name);
	new_elem->value = my_strdup(value);
	new_elem->next = NULL;
	while (env->next != NULL)
		env = env->next;
	env->next = new_elem;
}

void print_str_error(int error, int *ret_value)
{
	if (error == 1)
		my_printf("setenv: Variable name must begin with a letter.\n");
	else if (error == 2) {
		my_printf("setenv: Variable name must contain");
		my_printf(" alphanumeric characters.\n");
	}
	*ret_value = 1;
}

void setenv_func(char **str, shell_t shell, int *ret_value)
{
	int size = my_tablen(str);
	int str_error = verif_name_var(str[1]);

	if (str_error == 1) {
		print_str_error(1, ret_value);
		return;
	} else if (str_error == 2) {
		print_str_error(2, ret_value);
		return;
	}
	if (size == 1)
		env_func(str, shell, ret_value);
	else if (size < 4 && size > 1)
		add_elem_to_env(shell.env, str[1], str[2]);
	else {
		my_printf("%s: Too many arguments.\n", str[0]);
		*ret_value = 1;
	}
}
