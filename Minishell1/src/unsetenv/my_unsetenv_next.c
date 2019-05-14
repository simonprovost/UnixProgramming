/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

char **malloc_each_case_unset(char **env, char **new_env, int pos_remove_case)
{
	int j = 0;
	int i = 0;

	for (; env[j] != NULL ; j++) {
		if (j != pos_remove_case) {
			new_env[i] = malloc(sizeof(char *) * SIZE_ENV_J);
			i++;
		}
	}
	return (new_env);
}

char **fill_each_case_unset_unset(char **env, char **new_env, int pos)
{
	int j = 0;
	int i = 0;

	for (; env[j] != NULL ; j++) {
		if (j != pos) {
			new_env[i] = env[j];
			i++;
		}
	}
	new_env[i] = NULL;
	return (new_env);
}

int count_args_unsetenv_unset(char *s)
{
	int count = 0;

	for (int i = 9 ; s[i] != '\0' ; i++) {
		if (s[i] == ' ')
			count++;
	}
	return (count + 1);
}

void free_env_unset(info_t *info)
{
	for (int i = 0 ; info->env[i] != NULL ; i++)
		free(info->env[i]);
}

void find_in_path_unset(char *my_args, info_t *info)
{
	char **my_new_env = NULL;

	for (int i = 0 ; info->env[i] != NULL ; i++) {
		if (my_strncmp(my_args, info->env[i], STRLEN_ARGS - 1) == 0) {
			my_new_env = malloc(sizeof(char *) *
			size_env_setenv(info->env) - 1);
			my_new_env = malloc_each_case_unset(info->env,
			my_new_env, i);
			my_new_env = fill_each_case_unset_unset(info->env,
			my_new_env, i);
			info->env = my_strdup(my_new_env);
			break;
		}
	}
}
