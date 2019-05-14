/*
** EPITECH PROJECT, 2017
** null
** File description:
** null
*/

#include "minishell.h"

char *new_path_test(info_t *info, char *final_path, int i)
{
	if (info->info[0][0] != '/')
		final_path = fill_path(info->path[i], info->info[0]);
	else
		final_path = my_strdup_simple(info->info[0]);
	return (final_path);
}