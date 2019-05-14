/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

void set_env_func(char **my_info, char **env, info_t *info, int check_who_it)
{
	char **new_env = NULL;
	char *final_path = NULL;
	int check = 0;

	if (check_who_it != -84) {
		new_env = malloc(sizeof(char *) * size_env_setenv(env) +
		info->count_args);
		new_env = malloc_setenv(env, new_env,
		my_info_received, info);
		new_env = fill_each_case_setenv(env, new_env);
		final_path = my_strcat(my_info_received[1], "=");
		info->count_args >= 2 ? final_path =
		my_strcat(final_path, my_info_received[2]) : 0;
		new_env[size_env_setenv(env)] = final_path;
		new_env[size_env_setenv(env) + 1] = NULL;
		info->env = new_env;
		info->check_if_some_things_happened = 1;
	} else if (check != 1)
		handling_error(my_info_received, s, info);
}