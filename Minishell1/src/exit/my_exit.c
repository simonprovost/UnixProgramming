/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

void exit_func(char *s, info_t *info)
{
	int check_args = 0;

	if (s[4] == ' ' || s[4] == '\0') {
		for (int i = 0 ; s[i] != '\0' ; i++)
			s[i] == ' ' ? check_args += 1 : 0;
		check_args_exit(s, check_args, info);
	} else {
		print_correct_file_error(s);
		my_printf(": Command not found.\n");
	}
}