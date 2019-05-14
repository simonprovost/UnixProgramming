/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

int count_env(char **env)
{
	int i = 0;

	for (; env[i] != NULL; i++);
	return (i);
}

void fill_begin_info(info_t *info, int argc, char **env)
{
	info->argc = argc;
	info->env = my_strdup(env);
	info->run_env = 0;
	info->s = NULL;
	info->check_if_some_things_happened = 0;
	info->check_env_not_found = 0;
	info->pos_set_env = 0;
	info->check_setenv = 0;
	info->s_save = NULL;
	info->pos_old = 0;
	info->pos_current = 0;
}

char *fill_path(char *dest, char *src)
{
	char *final_path = NULL;

	final_path = my_strcat_shell(dest, src);
	return (final_path);
}
