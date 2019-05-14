/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

void manage_unsetenv(hashmap_t *hashmap, char *args, info_shell_t *info_shell)
{
	char **args_line = str_to_word_array(args);

	if (!args_line[1]) {
		my_printf("unsetenv: Too few arguments.\n");
		info_shell->return_value = 1;
		return;
	}
	for (int i = 1 ; i != count_env(args_line) ; i++) {
		info_shell->env = delete_case_hashmap(hashmap,
		args_line[i], info_shell->env);
	}
}