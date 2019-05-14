/*
** EPITECH PROJECT, 2017
** my_exec_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

void fill_info(info_t *info, char *str)
{
	info->size = 0;
	info->my_loc = 0;
	info->info = str_to_word_array(str);
	info->path = NULL;
	info->size_path_array = 0;
	info->path = str_to_word_array(info->env[info->pos_path]);
	info->count_args = 0;
	info->my_old_pwd = NULL;
	info->my_current_pwd = NULL;
}