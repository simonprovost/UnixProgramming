/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

int detect_who_is_it(info_t *info, char **my_info)
{
	for (int i = 0 ; info->env[i] != NULL ; i++) {
		if (my_strncmp(info->env[i], my_info[1],
			my_strlen(my_info[1])) == 0) {
			return (i);
		}
	}
	return (-84);
}

void pre_set_func(char **my_info_received, int comp, info_t *info, int *ch)
{
	if (my_info_received[1] == NULL && comp == 0) {
		info->check_setenv = 1;
		print_env(info);
	}
	if (my_info_received[1] != NULL)
		*ch = detect_who_is_it(info, my_info_received);
}

char **loop_set_env(char **env, char **new_env, char **my_info, info_t *info)
{
	new_env = malloc(sizeof(char *) * size_env_setenv(env) +
	info->count_args);
	new_env = malloc_setenv(env, new_env, my_info,
	info);
	new_env = fill_each_case_setenv(env, new_env);
	return (new_env);
}

void set_env_func_loop(char *s, char **env, info_t *info)
{
	int comp = my_strcmp(s, "setenv");
	char **new_env = NULL;
	char *final_path = NULL;
	char **my_info = str_to_word_array(s);
	int check = 0;
	int check_who_is_it = 0;

	pre_set_func(my_info, comp, info, &check_who_is_it);
	if (fail_args_three(s, info, check_who_is_it) == 0 && (CHECK_S == 0)
		&& check_info(my_info) == 0 && check_who_is_it == -84) {
		new_env = loop_set_env(env, new_env, my_info, info);
		final_path = my_strcat(my_info[1], "=");
		info->count_args >= 2 ? final_path = my_strcat(final_path,
		my_info[2]) : 0;
		new_env[size_env_setenv(env)] = final_path;
		new_env[size_env_setenv(env) + 1] = NULL;
		info->env = new_env;
		info->check_if_some_things_happened = 1;
	} else if (check != 1)
		handling_error(my_info, s, info, check_who_is_it);
}

void set_env_func(char *s, char **env, info_t *info)
{
	if (s[6] == ' ' || s[6] == '\0')
		set_env_func_loop(s, env, info);
	else {
		print_correct_file_error(s);
		my_printf(": Command not found.\n");
	}
	info->check_setenv = 0;
}