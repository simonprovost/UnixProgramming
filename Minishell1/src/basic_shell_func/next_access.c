/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

void next_access_func(char *final_path, info_t *info, int *check_if_one)
{
	(access(final_path, F_OK)
	!= -1 && info->run_env == 0) ? (show_programm_user(info, final_path,
	info->env), *check_if_one = 1) : 0;
}