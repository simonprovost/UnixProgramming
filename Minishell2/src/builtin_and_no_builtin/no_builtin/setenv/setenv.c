/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"


int alphanum_check(char *str)
{
	for (int i = 0 ; str[i] ; i++) {
		if (((str[i] >= '!' && str[i] <= '/')
		|| (str[i] >= 58 && str[i] <= 63)
		|| (str[i] >= 91 && str[i] <= 96)
		|| (str[i] >= 123 && str[i] <= 126))
		&& str[i] != '_') {
			return (1);
		}
	}
	return (0);
}

int error_handling(info_shell_t *info_shell)
{
	char **tab_path = split_setenv(info_shell->line);

	if (tab_path[1][0] >= '0' && tab_path[1][0] < '9') {
		my_printf(SETENV_ERR);
		return (84);
	} else if (alphanum_check(tab_path[1]) == 1) {
		my_printf(SETENV_ERR_ALPHA);
		return (84);
	}
	return (0);
}

void manage_setenv(hashmap_t *hashmap, char *args, info_shell_t *info_shell)
{
	char **args_line = NULL;

	if (!args)
		return;
	args_line = split_setenv(args);
	if (!args_line[1]) {
		print_tab(info_shell->env);
		return;
	}
	if (count_env(args_line) > 3) {
		my_printf("setenv: Too many arguments.\n");
		info_shell->return_value = 1;
		return;
	}
	if ((error_handling(info_shell)) == 84) {
		info_shell->return_value = 1;
		return;
	}
	info_shell->env = add_value_to_env(hashmap, args_line[1],
	args_line[2], info_shell->env);
}