/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** PSU_minishell1_2017 made by Sanchez Lucas
*/

#include "42sh.h"

int verif_env(char **env)
{
	int i = 0;

	if (env == NULL)
		return (0);
	while (env[i] != NULL) {
		if (env[i] != NULL)
			return (1);
		i++;
	}
	return (0);
}

void add_elem_to_created_env(env_t *env, char *name, char *value)
{
	env_t *tmp = malloc(sizeof(*tmp));

	while (env->next != NULL)
		env = env->next;
	tmp->name = my_strdup(name);
	tmp->value = my_strdup(value);
	tmp->next = NULL;
	env->next = tmp;
}

env_t *fill_my_env(env_t *env)
{
	char *pwd = malloc(sizeof(char) * 4096);

	pwd = getcwd(pwd, 4096);
	env = malloc(sizeof(*env));
	env->value = NULL;
	env->next = NULL;
	add_elem_to_created_env(env,
	"PATH", "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin");
	add_elem_to_created_env(env, "PWD", pwd);
	return (env);
}
