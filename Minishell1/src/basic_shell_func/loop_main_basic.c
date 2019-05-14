/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

void analyse_user_input(info_t *info, char *s, char *final_path)
{
	int check = 0;

	info->s_save = s;
	info->run_env = 0;
	check = check_if_built_in(s, info);
	fill_info(info, s);
	found_size_path_array(info);
	check == 0 ? test_if_you_have_access(info, final_path) : 0;
}
