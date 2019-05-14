/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

void unset_env_func_loop(char *s, char **env, info_t *info)
{
	int comp = my_strcmp(s, "unsetenv");
	int count_args = 0;
	char **my_args = NULL;
	char *str_to_fin_in_path = NULL;
	int check = 0;
	UNUSED(env);

	if (comp == 0) {
		check = 1;
		my_printf("unsetenv: Too few arguments.\n");
	} else
		info->check_if_some_things_happened = 1;
	if (check == 0) {
		count_args = count_args_unsetenv_unset(s) + 1;
		my_args = str_to_word_array(s);
		for (int i = 1; i < count_args; i++) {
			str_to_fin_in_path = my_strcat(my_args[i], "=");
			find_in_path_unset(str_to_fin_in_path, info);
		}
	}
}

void unset_env_func(char *s, char **env, info_t *info)
{
	if (s[8] == ' ' || s[8] == '\0')
		unset_env_func_loop(s, env, info);
	else {
		print_correct_file_error(s);
		my_printf(": Command not found.\n");
	}
}