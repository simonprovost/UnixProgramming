/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

void env_print_func_loop(info_t *info)
{
	print_env(info);
	info->run_env = 1;
	info->check_if_some_things_happened = 1;
}

void env_print_func(char *s, info_t *info)
{
	if (s[3] == '\0')
		env_print_func_loop(info);
	else if (s[4] != '-' && s[5] != 'i'){
		print_correct_file_error(s);
		my_printf(": Command not found.\n");
	}
}
