/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

int func_to_read_size(info_t *info)
{
	int i = 0;

	for (; info->env[i] != NULL ; i++);
	return (i);
}

int func_to_found_old(info_t *info)
{
	for (int i = 0 ; info->env[i] != NULL ; i++) {
		if (my_strncmp("OLDPWD=", info->env[i], 6) == 0)
			return (i);
	}
	return (0);
}

int func_to_found_pwd(info_t *info)
{
	for (int i = 0 ; info->env[i] != NULL ; i++) {
		if (my_strncmp("PWD=", info->env[i], 3) == 0)
			return (i);
	}
	return (0);
}
